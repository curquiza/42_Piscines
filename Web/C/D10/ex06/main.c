/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/17 18:11:33 by curquiza          #+#    #+#             */
/*   Updated: 2016/08/18 14:18:58 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "op.h"
#include "display.h"

int		ft_check_op(char *op)
{
	int		i;

	i = 0;
	while (op[i] != '\0')
		i++;
	if (i == 1)
	{
		if (op[0] == '+' || op[0] == '-' || op[0] == '*' || op[0] == '/'
			|| op[0] == '%')
			return (1);
		else
			return (0);
	}
	else
		return (0);
}

int		ft_atoi(char *str)
{
	int		test_neg;
	int		i;
	int		result;

	i = 0;
	test_neg = 1;
	result = 0;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == ' ')
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		test_neg = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		result = result * 10;
		result = result + str[i] - 48;
		i++;
	}
	return (test_neg * result);
}

void	ft_init(char *tab, int (*f[5])(int, int))
{
	f[0] = &ft_add;
	f[1] = &ft_sous;
	f[2] = &ft_mult;
	f[3] = &ft_div;
	f[4] = &ft_mod;
	tab[0] = '+';
	tab[1] = '-';
	tab[2] = '*';
	tab[3] = '/';
	tab[4] = '%';
}

int		main(int argc, char **argv)
{
	int		(*f[5])(int, int);
	char	tab[5];
	int		i;

	ft_init(tab, f);
	i = -1;
	if (argc != 4)
		return (0);
	if (ft_check_op(argv[2]) == 0)
	{
		write(1, "0\n", 2);
		return (0);
	}
	while (i++ < 6)
		if (argv[2][0] == tab[i])
		{
			if (argv[2][0] == '/' && ft_atoi(argv[3]) == 0)
				ft_putstr("Stop : division by zero");
			else if (argv[2][0] == '%' && ft_atoi(argv[3]) == 0)
				ft_putstr("Stop : modulo by zero");
			else
				ft_putnbr(f[i](ft_atoi(argv[1]), ft_atoi(argv[3])));
			ft_putchar('\n');
		}
	return (0);
}
