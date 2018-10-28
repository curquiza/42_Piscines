#include "ft_list.h"

t_list		*ft_create_elem(void *data);
void		ft_putstr(char *str);


//void		ft_print_list(t_list *list)


int			main (int argc, char **argv)
{
	t_list		*list;

	list = 0;
	if (argc != 2)
		return (0);
	list = ft_create_elem(argv[1]);
	ft_putstr(list->data);
	return (0);
}
