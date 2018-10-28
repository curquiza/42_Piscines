#include "ft_list.h"
#include <stdio.h>

void		ft_putstr(char *str);
int			ft_putchar(char c);
int			ft_strcmp(char *s1, char *s2);
t_list		*ft_list_push_params(int ac, char **av);
void		ft_list_foreach_if(t_list *begin_list, void (*f)(void *), void *data_ref, int (*cmp)());

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
	t_list		*list;

	//(void)argv;
	//(void)argc;
	list = 0;
	list = ft_list_push_params(argc, argv);	
	ft_printlist(list);
	ft_putchar('\n');
	ft_list_foreach_if(list, &ft_putTEST, "test", &ft_strcmp);
	return (0);
}
