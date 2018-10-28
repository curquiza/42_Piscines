#include "ft_stock_par.h"

int		ft_strlen(char *str);
char	*ft_strdup(char *src);
char	**ft_split_whitespaces(char *str);


int		main(int argc, char **argv)
{
	t_stock_par		*tab;

	tab = ft_param_to_tab(argc, argv);
	ft_show_tab(tab);
	return (0);
}
