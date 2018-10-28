#include "ft_stock_par.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	t_stock_par		*tab_struct;
	int				i;
	int				j;

	tab_struct = ft_param_to_tab(argc, argv);
	i = 0;
	while (i < argc)
	{
		printf("%s\n", tab_struct[i].copy);
		printf("%d\n", tab_struct[i].size_param);
		j = 0;
		while (tab_struct[i].tab[j] != 0)
		{
			printf("%s\n", tab_struct[i].tab[j]);
			j++;
		}
		i++;
		printf("\n");
	}
	return (0);	
}
