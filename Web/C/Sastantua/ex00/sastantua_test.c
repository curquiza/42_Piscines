/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/06 15:53:43 by curquiza          #+#    #+#             */
/*   Updated: 2016/08/07 13:10:15 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_putchar(char c);

int		ft_base(int size)
{
	int		step;
	int		step_base;
	int		floor;
	int		floor_height;

	floor = 1;
	step = 1;
	step_base = 1;
	floor_height = 0;
	while (floor <= size)
	{
		floor_height =  floor + 2;
		step = 1;
		while (step <= floor_height)
		{
			step_base = step_base + 2;
			step++;
		}
		floor++;
		if (floor <= size)
			step_base = step_base + floor / 2 * 2 + 2;
	}
	return (step_base);
}

void	ft_putspace(int base, int step_base)
{
	int		i;
	int		nb_spaces;

	i = 1;
	nb_spaces = (base - step_base) / 2;
	while (i <= nb_spaces)
	{
		ft_putchar(' ');
		i++;
	}
}

void	ft_putbricks(int step_base, int step, int floor, int size)
{
	int		i;
	int		door;

	ft_putchar('/');
	door = (floor - 1) / 2 * 2 + 1; // si cest impair ca change rien door = floor, sinon door = floor - 1
	i = 1;
	while (i <= step_base - 2) //jusqua -2 car les / et \ sont deja mis.
	{
		if (size >= 5 && floor == size && step > floor + 2 - door
			&& i >= (step_base - door) / 2  && i < (step_base + door) / 2)
			if (step == floor + 2 - door + (door + 1) / 2
				&& i == (step_base + door) / 2 - 2)
				ft_putchar('$');
			else
				ft_putchar('|');
		else
			ft_putchar('*');

		i++;
	}
	ft_putchar('\\');
}

void	sastantua(int size)
{
	int		floor;
	int		step;
	int		step_base;
	int		i;

	i = 1;
	floor = 1;
	step_base = 1;
	while (floor <= size)
	{
		step = 1;
		while (step <= floor + 2)
		{
			step_base = step_base + 2;
			ft_putspace(ft_base(size), step_base);
			ft_putbricks(step_base, step, floor, size);
			ft_putchar('\n');
			step++;
		}
		floor++;
		step_base = step_base + floor / 2 * 2 + 2; // si le floor est pair, ca change rien, sil est impair cela le ramene a un floor pair.
	}
}
