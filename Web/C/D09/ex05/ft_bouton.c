/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bouton.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 10:39:50 by curquiza          #+#    #+#             */
/*   Updated: 2016/08/12 11:02:35 by curquiza         ###   ########.fr       */
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

int		ft_bouton(int i, int j, int k)
{
	int		tab[3];

	tab[0] = i;
	tab[1] = j;
	tab[2] = k;
	ft_sort_integer_table(tab, 3);
	return (tab[1]);
}
