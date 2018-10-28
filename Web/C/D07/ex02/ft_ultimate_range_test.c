/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/13 22:13:01 by curquiza          #+#    #+#             */
/*   Updated: 2016/08/16 11:15:43 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int				i;
	unsigned int	length;
	
	length = max - min;
	if (min >=  max || length > 2147483647)
	{
		range = NULL;
		return (0);
	}
	else
	{i = 0;
	*range = (int*)malloc(sizeof(int) * (max - min));
	while (i < max - min)
	{
		(*range)[i] = min + i;
		i++;
	}
	return (i);}
}
