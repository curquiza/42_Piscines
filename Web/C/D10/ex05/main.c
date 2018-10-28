#include <stdio.h>
#include <stdlib.h>

int		ft_is_sort(int *tab, int length, int (*f)(int, int));

int		ft_test(int a, int b)
{
	if (a > b)
		return (1);
	else if (a < b)
		return (-1);
	else
		return (0);
}

int		main(void)
{
	//int		tab[6] = {100, 20, 4, 4, -2, -201};
	int		tab2[6] = {-4, -4, -4, -4, -4, -4};
	int		length;

	length = 6;
	printf("%d\n", ft_is_sort(tab2, length,  &ft_test)); 
}
