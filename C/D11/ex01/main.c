#include "ft_list.h"

void		ft_putstr(char *str);
int			ft_putchar(char c);

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
	list = ft_create_elem("TEST");
	ft_list_push_back(&list, "FIN");
	ft_printlist(list);
	return (0);
}
