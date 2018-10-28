/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_takes_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 18:52:26 by curquiza          #+#    #+#             */
/*   Updated: 2016/08/11 21:30:10 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
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

void	ft_display(int hour, int hour2, char c1, char c2)
{
	write(1, "THE FOLLOWING TAKES PLACE BETWEEN ", 34);
	ft_putnbr(hour);
	write(1, ".00 ", 4);
	ft_putchar(c1);
	write(1, ".M. AND ", 8);
	ft_putnbr(hour2);
	write(1, ".00 ", 4);
	ft_putchar(c2);
	write(1, ".M.\n", 4);
}

void	ft_special_hours(int *hour, int *hour2, char *c1, char *c2)
{
	if (*hour == 0)
	{
		*hour = 12;
		*hour2 = 1;
	}
	if (*hour == 11 && *c1 == 'A')
		*c2 = 'P';
	else if (*hour == 11 && *c1 == 'P')
		*c2 = 'A';
}

void	ft_takes_place(int hour)
{
	char	c1;
	char	c2;
	int		hour2;

	c1 = 0;
	c2 = 0;
	if (hour >= 0 && hour <= 11)
	{
		c1 = 'A';
		c2 = 'A';
	}
	else if (hour > 11 && hour < 24)
	{
		c1 = 'P';
		c2 = 'P';
		hour = hour - 12;
	}
	hour2 = hour + 1;
	ft_special_hours(&hour, &hour2, &c1, &c2);
	ft_display(hour, hour2, c1, c2);
}
