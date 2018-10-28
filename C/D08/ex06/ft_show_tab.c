/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 17:32:09 by curquiza          #+#    #+#             */
/*   Updated: 2016/08/16 19:17:47 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_par.h"

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (*(str + i) != '\0')
	{
		ft_putchar(*(str + i));
		i++;
	}
}

void	ft_putnbr(int nb)
{
	int index;
	int tab[10];

	index = 0;
	if (nb < 0)
		ft_putchar('-');
	while (index < 10 && (nb >= 10 || nb <= -10))
	{
		tab[index] = (nb % 10);
		nb = nb / 10;
		index++;
	}
	tab[index] = nb;
	while (index >= 0)
	{
		if (tab[index] < 0)
			ft_putchar((tab[index] * -1) + '0');
		else
			ft_putchar(tab[index] + '0');
		index--;
	}
}

void	ft_show_tab(struct s_stock_par *par)
{
	int				i;
	int				j;

	i = 0;
	while (par[i].str != 0)
	{
		ft_putstr(par[i].copy);
		ft_putchar('\n');
		ft_putnbr(par[i].size_param);
		ft_putchar('\n');
		j = 0;
		while (par[i].tab[j] != 0)
		{
			ft_putstr(par[i].tab[j]);
			ft_putchar('\n');
			j++;
		}
		i++;
	}
}
