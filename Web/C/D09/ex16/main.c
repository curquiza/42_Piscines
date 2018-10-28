#include <stdio.h>

unsigned int	ft_active_bits(int value);

int		main(void)
{
	printf("%d\n", ft_active_bits(2));
	printf("%d\n", ft_active_bits(3));
	printf("%d\n", ft_active_bits(4));
	printf("%d\n", ft_active_bits(12));
	return (0);
}
