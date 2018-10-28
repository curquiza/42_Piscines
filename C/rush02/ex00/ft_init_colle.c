/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_colle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/20 22:02:11 by curquiza          #+#    #+#             */
/*   Updated: 2016/08/21 11:36:37 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colle_2.h"
#include "ft_init_colle.h"

void	ft_init_colle00(t_colle *colle, int x, int y)
{
	colle->up_left = 'o';
	colle->up_right = 'o';
	colle->b_left = 'o';
	colle->b_right = 'o';
	colle->col = '|';
	colle->row = '-';
	colle->nb_col = x;
	colle->nb_row = y;
}

void	ft_init_colle01(t_colle *colle, int x, int y)
{
	colle->up_left = '/';
	colle->up_right = '\\';
	colle->b_left = '\\';
	colle->b_right = '/';
	colle->col = '*';
	colle->row = '*';
	colle->nb_col = x;
	colle->nb_row = y;
}

void	ft_init_colle02(t_colle *colle, int x, int y)
{
	colle->up_left = 'A';
	colle->up_right = 'A';
	colle->b_left = 'C';
	colle->b_right = 'C';
	colle->col = 'B';
	colle->row = 'B';
	colle->nb_col = x;
	colle->nb_row = y;
}

void	ft_init_colle03(t_colle *colle, int x, int y)
{
	colle->up_left = 'A';
	colle->up_right = 'C';
	colle->b_left = 'A';
	colle->b_right = 'C';
	colle->col = 'B';
	colle->row = 'B';
	colle->nb_col = x;
	colle->nb_row = y;
}

void	ft_init_colle04(t_colle *colle, int x, int y)
{
	colle->up_left = 'A';
	colle->up_right = 'C';
	colle->b_left = 'C';
	colle->b_right = 'A';
	colle->col = 'B';
	colle->row = 'B';
	colle->nb_col = x;
	colle->nb_row = y;
}
