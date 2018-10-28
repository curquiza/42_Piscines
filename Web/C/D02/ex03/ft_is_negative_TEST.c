#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_is_negative(int n)
{
	if (n >= 0)
		ft_putchar('P');
	else
		ft_putchar('N');
}

int		main(int argc, char *argv[])
{
	ft_is_negative(0);
	ft_is_negative(5);
	ft_is_negative(-12);
	return (0);
}
