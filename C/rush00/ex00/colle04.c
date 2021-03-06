/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle04.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/06 11:57:08 by curquiza          #+#    #+#             */
/*   Updated: 2016/08/07 16:20:13 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	ft_print_line(char char1, char char2, char char3, int x)
{
	int		i;

	i = 0;
	while (i < x)
	{
		if (i == 0)
			ft_putchar(char1);
		else if (i == x - 1)
			ft_putchar(char3);
		else
			ft_putchar(char2);
		i++;
	}
}

void	colle(int x, int y)
{
	int j;

	j = 0;
	if (x > 0 && y > 0)
	{
		while (j < y)
		{
			if (j == 0)
				ft_print_line('A', 'B', 'C', x);
			else if (j == y - 1)
				ft_print_line('C', 'B', 'A', x);
			else
				ft_print_line('B', ' ', 'B', x);
			ft_putchar('\n');
			j++;
		}
	}
}
