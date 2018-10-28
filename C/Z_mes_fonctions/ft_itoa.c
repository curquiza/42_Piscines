/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 20:36:05 by exam              #+#    #+#             */
/*   Updated: 2016/08/12 21:12:37 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_itoa(int nbr)
{
	char	*str;
	int		i;
	int		j;
	char	buffer;

	str = (char*)malloc(12);
	i = 0;
	j = 0;
	if (nbr < 0)
	{
		str[0] = '-';
		j++;
		i++;
	}
	while (i < 11 && (nbr >= 10 || nbr <= -10))
	{
		if (nbr % 10 < 0)	
			str[i] = '0' + -1 * (nbr % 10);
		else
			str[i] = '0' + nbr % 10;
		nbr = nbr / 10;
		i++;
	}
	if (nbr % 10 < 0)	
		str[i] = '0' + -1 * (nbr % 10);
	else
		str[i] = '0' + nbr % 10;
	str[i + 1] = '\0';
	while (i > j)
	{
		buffer = str[i];
		str[i] = str[j];
		str[j] = buffer;
		i--;
		j++;
	}
	return (str);
}
