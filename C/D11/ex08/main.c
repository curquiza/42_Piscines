#include "ft_list.h"

void		ft_putstr(char *str);
int			ft_putchar(char c);
t_list		*ft_list_push_params(int ac, char **av);
t_list		*ft_create_elem(void *data);

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

	(void)argv;
	(void)argc;
	list = 0;
	list = ft_list_push_params(argc, argv);	
	ft_printlist(list);
	ft_putchar('\n');
	ft_list_reverse(&list);
	ft_printlist(list);
	return (0);
}
