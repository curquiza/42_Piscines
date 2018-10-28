#include <stdio.h>

int		*ft_map(int *tab, int length, int(*f)(int));

int		ft_test(int nb)
{
	return (nb + 42);
}

int		main(void)
{
	int		i;
	int		tab[6] = {0, 1, 2, 3, 4, 5};
	int		l;
	int		*tab2;

	l = 6;
	i = 0;
	tab2 = ft_map(tab, l, &ft_test);
	while (i < l)
	{
		printf("%d\n", tab2[i]);
		i++;
	}
	return (0);
}
