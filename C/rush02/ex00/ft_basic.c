/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/20 22:11:23 by curquiza          #+#    #+#             */
/*   Updated: 2016/08/20 22:14:37 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_basic.h"

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

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

int		ft_strcmp(char *s1, char *s2)
{
	int		i;
	int		length;

	i = 0;
	length = 0;
	while (s1[length] != '\0')
		length++;
	while (i <= length)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

char	*ft_strcat(char *dest, char *src)
{
	int		i;
	int		j;

	i = 0;
	while (dest[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
