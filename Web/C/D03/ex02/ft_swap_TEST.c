#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int		buffer;

	buffer = *a;
	*a = *b;
	*b = buffer;
}

int		main(void)
{
	int		a;
	int		b;

	a = 1;
	b = 0;
	ft_swap(&a, &b);
	printf("a = %d et b=%d", a, b);
	return (0);
}
