/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/13 10:10:49 by curquiza          #+#    #+#             */
/*   Updated: 2016/08/13 19:55:17 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

int		ft_ok_col(int grid[9][9], int value, int i, int j)
{
	i = 0;
	while (i < 9)
	{
		if (grid[i][j] == value)
			return (0);
		i++;
	}
	return (1);
}

int		ft_ok_row(int grid[9][9], int value, int i, int j)
{
	j = 0;
	while (j < 9)
	{
		if (grid[i][j] == value)
			return (0);
		j++;
	}
	return (1);
}

int		ft_ok_block(int grid[9][9], int value, int i, int j)
{
	int		i0;
	int		j0;

	i0 = i - i % 3;
	j0 = j - j % 3;
	i = i0;
	j = j0;
	while (i < i0 + 3)
	{
		j = j0;
		while (j < j0 + 3)
		{
			if (grid[i][j] == value)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		ft_valid_place(int grid[9][9], int value, int i, int j)
{
	if (ft_ok_col(grid, value, i, j) == 1 && ft_ok_row(grid, value, i, j) == 1
		&& ft_ok_block(grid, value, i, j) == 1)
		return (1);
	else
		return (0);
}

void	ft_atoi_argv(char **argv, int grid[9][9])
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			if (argv[i + 1][j] >= '1' && argv[i + 1][j] <= '9')
				grid[i][j] = argv[i + 1][j] - '0';
			else
				grid[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	ft_display_sudoku(int grid[9][9])
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			if (grid[i][j] <= 9)
				ft_putchar('0' + grid[i][j]);
			if (j != 8)
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int		ft_solver_sudoku(int grid[9][9], int loc)
{
	int		k;
	int		i;
	int		j;

	k = 1;
	i = loc / 9;
	j = loc % 9;
	if (loc == 81)
		return (1);
	else if (grid[i][j] != 0)
		return (ft_solver_sudoku(grid, loc + 1));
	while (k <= 9)
	{
		if (ft_valid_place(grid, k, i, j) == 1)
		{
			grid[i][j] = k;
			if (ft_solver_sudoku(grid, loc + 1) == 1)
				return (1);
		}
		k++;
	}
	grid[i][j] = 0;
	return (0);
}

int		ft_check(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] < 49 || str[i] > 57) && str[i] != 46)
			return (0);
		i++;
	}
	if (i != 9)
		return (0);
	else
		return (1);
}

int		main(int argc, char **argv)
{
	int		i;
	int		grid[9][9];

	i = 1;
	if (argc != 10)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	while (i <= 9)
	{
		if (ft_check(argv[i]) == 0)
		{
			write(1, "Error\n", 6);
			return (0);
		}
		i++;
	}
	ft_atoi_argv(argv, grid);
	if (ft_solver_sudoku(grid, 0) == 0)
		write(1, "Error\n", 6);
	else
		ft_display_sudoku(grid);
	return (0);
}
