#include "ft_list.h"

void		ft_putstr(char *str);
int			ft_putchar(char c);
t_list		*ft_list_at(t_list *begin_list, unsigned int nbr);
t_list		*ft_list_push_params(int ac, char **av);

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
	t_list		*nieme_list;

	(void)argv;
	(void)argc;
	list = 0;
	list = ft_list_push_params(argc, argv);	
	ft_printlist(list);
	ft_putchar('\n');
	nieme_list = ft_list_at(list, 0);
	ft_printlist(nieme_list);
	return (0);
}
