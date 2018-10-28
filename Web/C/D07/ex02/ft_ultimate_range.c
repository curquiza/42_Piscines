/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/13 22:13:01 by curquiza          #+#    #+#             */
/*   Updated: 2016/08/15 12:48:43 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int		i;

	i = 0;
	if (min >= max)
	{
		range = NULL;
		return (0);
	}
	*range = (int*)malloc(sizeof(int) * (max - min));
	while (i < max - min)
	{
		(*range)[i] = min + i;
		i++;
	}
	return (i);
}
