#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int		buffer_a;
	int		buffer_b;

	buffer_a = *a;
	buffer_b = *b;
	*a = buffer_a / buffer_b;
	*b = buffer_a % buffer_b;
}

int		main(void)
{
	int		a;
	int		b;

	a = 10;
	b = 3;
	ft_ultimate_div_mod(&a, &b);
	printf("a=%d b=%d", a, b);
	return (0);
}
