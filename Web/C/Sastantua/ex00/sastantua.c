/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/06 15:53:43 by curquiza          #+#    #+#             */
/*   Updated: 2016/08/07 14:44:29 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

int		ft_base(int size)
{
	int		step;
	int		step_base;
	int		floor;

	floor = 1;
	step = 1;
	step_base = 1;
	while (floor <= size)
	{
		step = 1;
		while (step <= floor + 2)
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
	door = (floor - 1) / 2 * 2 + 1;
	i = 1;
	while (i <= step_base - 2)
	{
		if (floor == size && step > floor + 2 - door
			&& i >= (step_base - door) / 2 && i < (step_base + door) / 2)
			if (size >= 5 && step == floor + 2 - door + (door + 1) / 2
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
		step_base = step_base + floor / 2 * 2 + 2;
	}
}
