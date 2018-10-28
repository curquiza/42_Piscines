/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/20 17:01:23 by curquiza          #+#    #+#             */
/*   Updated: 2016/08/21 11:52:54 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "colle_2.h"
#include "ft_init_colle.h"
#include "ft_basic.h"

char	*ft_print_line(char char1, char char2, char char3, int x)
{
	int		i;
	char	*str;

	str = (char *)malloc(sizeof(char) * x);
	i = 0;
	while (i < x)
	{
		if (i == 0)
			str[i] = char1;
		else if (i == x - 1)
			str[i] = char3;
		else
			str[i] = char2;
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	ft_colle(int x, int y, char *str, t_colle colle)
{
	int		j;

	j = 0;
	if (x > 0 && y > 0)
	{
		while (j < y)
		{
			if (j == 0)
				str = ft_strcat(str, ft_print_line(colle.up_left, colle.row,
													colle.up_right, x));
			else if (j == y - 1)
				str = ft_strcat(str, ft_print_line(colle.b_left, colle.row,
													colle.b_right, x));
			else
				str = ft_strcat(str, ft_print_line(colle.col, ' ',
													colle.col, x));
			while (*str != '\0')
				str++;
			*str = '\n';
			j++;
		}
		str++;
		*str = '\0';
	}
}

void	ft_calc_row_col(t_colle *colle, char *buffer)
{
	int		i;

	i = 0;
	colle->nb_col = 0;
	colle->nb_row = 0;
	while (buffer[i] != '\n')
		i++;
	colle->nb_col = i;
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '\n')
			colle->nb_row = colle->nb_row + 1;
		i++;
	}
}

char	**ft_complete_all_colles(int x, int y)
{
	char	**str;
	t_colle	*colle;
	int		i;

	i = 0;
	colle = (t_colle *)malloc(sizeof(t_colle) * 5);
	str = (char **)malloc(sizeof(char*) * 5);
	ft_init_colle00(colle, x, y);
	ft_init_colle01(colle + 1, x, y);
	ft_init_colle02(colle + 2, x, y);
	ft_init_colle03(colle + 3, x, y);
	ft_init_colle04(colle + 4, x, y);
	while (i <= 4)
	{
		str[i] = (char *)malloc(sizeof(char) * (SIZE_BUF + 1));
		ft_colle(x, y, str[i], colle[i]);
		i++;
	}
	return (str);
}

void	ft_find_colle(char *buf, char **str, int x, int y)
{
	int		i;
	int		cpt;

	cpt = 0;
	i = 0;
	while (i < 5)
	{
		if (ft_strcmp(str[i], buf) == 0)
		{
			if (cpt > 0)
				ft_putstr(" || ");
			ft_putstr("[colle-0");
			ft_putnbr(i);
			ft_putstr("] [");
			ft_putnbr(x);
			ft_putstr("] [");
			ft_putnbr(y);
			ft_putchar(']');
			cpt++;
		}
		i++;
	}
	if (cpt == 0)
		ft_putstr("aucune");
	ft_putchar('\n');
}
