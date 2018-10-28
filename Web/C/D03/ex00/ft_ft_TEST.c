#include <stdio.h>

void	ft_ft(int *nbr)
{
	*nbr = 42;
}
int		main(void)
{
	int		*ptr;
	ft_ft(ptr);
	printf("%d", *ptr);
	return (0);
}
