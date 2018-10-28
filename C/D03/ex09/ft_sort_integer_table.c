/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_integer_table.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/05 12:23:26 by curquiza          #+#    #+#             */
/*   Updated: 2016/08/05 13:26:06 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_integer_table(int *tab, int size)
{
	int		buffer;
	int		i;
	int		j;
	int		loc_min;

	i = 0;
	j = 0;
	while (i < size)
	{
		loc_min = i;
		j = i + 1;
		while (j <= size)
		{
			if (tab[loc_min] > tab[j])
				loc_min = j;
			j++;
		}
		buffer = tab[i];
		tab[i] = tab[loc_min];
		tab[loc_min] = buffer;
		i++;
	}
}
