#include "ft_list.h"
#include <stdio.h>
#include <stdlib.h>

void		ft_putstr(char *str);
int			ft_putchar(char c);
int			ft_strcmp(char *s1, char *s2);
t_list		*ft_list_push_params(int ac, char **av);
void		ft_list_merge(t_list **begin_list1, t_list *begin_list2);

void	ft_putTEST(void *str)
{
	printf("%s", str);
}

void		ft_printlist(t_list *list)
{
	while (list != 0)
	{
		ft_putstr(list->data);
		ft_putchar('\n');
		list = list->next;
	}
}

int			main(int argc, char **argv)
{
	t_list		*list1;
	t_list		*list2;

	//(void)argv;
	//(void)argc;
	list1 = 0;
	list1 = ft_list_push_params(argc, argv);
	list2 = 0;
	list2 = ft_list_push_params(argc, argv);	
	ft_printlist(list1);
	ft_putchar('\n');
	ft_printlist(list2);
	ft_putchar('\n');
	ft_list_merge(&list1, list2);
	ft_printlist(list1);
	return (0);
}
