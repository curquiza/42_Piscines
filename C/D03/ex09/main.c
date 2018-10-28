/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/04 20:33:40 by curquiza          #+#    #+#             */
/*   Updated: 2016/08/05 13:26:10 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_sort_integer_table(int *tab, int size);

int		main(void)
{
	int tab[10] = {12, -78, 0, 45, 1, -1, 0, 1, 457512, -12458};
	int i;

	ft_sort_integer_table(tab, 10);
	i = 0;
	while (i < 10)
	{
		printf("%d ", tab[i]);
		i++;
	}
	return (0);
}
