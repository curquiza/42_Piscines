#include <unistd.h>

int		ft_putchar(char c);

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

void	ft_print_comb2(void)
{
	int i;
	int j;

	i = -1;
	j = 1;
	while (i++ <= 97)
	{
		while (j <= 99)
		{
			ft_putchar('0' + i / 10);
			ft_putchar('0' + i % 10);
			ft_putchar(' ');
			ft_putchar('0' + j / 10);
			ft_putchar('0' + j % 10);
			ft_putchar(',');
			ft_putchar(' ');
			j++;
		}
		j = i + 2;
	}
	ft_putchar('0' + i / 10);
	ft_putchar('0' + i % 10);
	ft_putchar(' ');
	ft_putchar('0' + (j - 1) / 10);
	ft_putchar('0' + (j - 1) % 10);
}

/*void	ft_print_comb2(void)
{
	char	number1;
	char	number2;
	char	number3;
	char	number4;

	number1 = '0';
	number2 = '0';
	number3 = '0';
	number4 = '1';
	while (number1 <= '9')
	{
		while (number2 <= '8')
		{
			while (number3 <= '9')
			{
				while (number4 <= '9')
				{
					ft_putchar(number1);
					ft_putchar(number2);
					ft_putchar(' ');
					ft_putchar(number3);
					ft_putchar(number4);
					ft_putchar(',');
					ft_putchar(' ');
					number4++;
				}
				number3++;
				number4 = '0';
				ft_putchar('\n');
			}
			number2++;
			number3 = '0';
		}
		number1++;
		number2 = '0';
	}
}*/

int		main(void)
{
	ft_print_comb2();
	return (0);
}
