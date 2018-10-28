/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 22:36:25 by curquiza          #+#    #+#             */
/*   Updated: 2016/08/04 11:26:40 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	ft_print_delimiter(void)
{
	ft_putchar(',');
	ft_putchar(' ');
}

void	ft_print_3_numbers(int number1, int number2, int number3)
{
	ft_putchar(number1);
	ft_putchar(number2);
	ft_putchar(number3);
}

void	ft_print_comb(void)
{
	char	number1;
	char	number2;
	char	number3;

	number1 = '0';
	number2 = number1 + 1;
	number3 = number2 + 1;
	while (number1 < '7')
	{
		while (number2 <= '8')
		{
			while (number3 <= '9')
			{
				ft_print_3_numbers(number1, number2, number3);
				ft_print_delimiter();
				number3++;
			}
			number2++;
			number3 = number2 + 1;
		}
		number1++;
		number2 = number1 + 1;
		number3 = number2 + 1;
	}
	ft_print_3_numbers(number1, number2, number3);
}
