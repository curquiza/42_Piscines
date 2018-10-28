/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle00.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/06 14:32:09 by curquiza          #+#    #+#             */
/*   Updated: 2016/08/07 17:12:57 by curquiza         ###   ########.fr       */
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
			if (j == 0 || j == y - 1)
				ft_print_line('o', '-', 'o', x);
			else
				ft_print_line('|', ' ', '|', x);
			ft_putchar('\n');
			j++;
		}
	}
}
