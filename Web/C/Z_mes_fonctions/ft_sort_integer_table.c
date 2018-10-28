/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_integer_table.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/05 12:23:26 by curquiza          #+#    #+#             */
/*   Updated: 2016/08/12 11:07:50 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_integer_table(int *tab, int size)
{
	int		buffer;
	int		i;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			buffer = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = buffer;
			i = 0;
		}
		else
			i++;
	}
}
