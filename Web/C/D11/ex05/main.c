#include "ft_list.h"
#include <stdlib.h>

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

int			main(int argc, char **argv)
{
	t_list		*list;
	//char		**tab;

	//(void)argv;
	(void)argc;
	list = 0;
	//tab = NULL;
	//tab = (char**)malloc(sizeof(char*) * 4);
	//list = ft_create_elem("TEST");
	list = ft_list_push_params(0, argv);	
	ft_printlist(list);
	return (0);
}
