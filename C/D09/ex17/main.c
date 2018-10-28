#include <stdio.h>

int		ft_max(int *tab, int length);

int		main(void)
{
	int		tab[6] = {1, 2, 178, -45, 12457, 0};
	printf("%d\n", ft_max(tab, 6));
	return (0);
}

