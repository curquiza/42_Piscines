#include <stdio.h>

unsigned int	ft_collatz_conjecture(unsigned int base);
int				ft_atoi(char *str);

int				main(void)
{
	printf("%d\n", ft_collatz_conjecture(1));
	printf("%d\n", ft_collatz_conjecture(0));
	printf("%d\n", ft_collatz_conjecture(2));
	printf("%d\n", ft_collatz_conjecture(3));
	printf("%d\n", ft_collatz_conjecture(15));
	return (0);
}
