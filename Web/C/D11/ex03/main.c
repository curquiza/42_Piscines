#include "ft_list.h"

void		ft_putstr(char *str);
void		ft_putnbr(int nb);
int			ft_putchar(char c);
void		ft_list_push_back(t_list **begin_list, void *data);
void		ft_list_push_front(t_list **begin_list, void *data);

void		ft_printlist(t_list *list)
{
	while (list != 0)
	{
		ft_putstr(list->data);
		ft_putchar('\n');
		list = list->next;
	}
}

int			main(void)
{
	t_list		*list;

	list = 0;
	//list = ft_create_elem("TEST");
	//ft_list_push_front(&list, "DEBUT");
	//ft_list_push_back(&list, "FIN");
	//ft_list_push_back(&list, "FIN2");
	ft_putnbr(ft_list_size(list));
	ft_putchar('\n');
	ft_printlist(list);
	return (0);
}
