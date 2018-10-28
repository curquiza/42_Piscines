/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/17 22:46:32 by curquiza          #+#    #+#             */
/*   Updated: 2016/08/17 22:51:06 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

int		ft_add(int a, int b)
{
	return (a + b);
}

int		ft_sous(int a, int b)
{
	return (a - b);
}

int		ft_mult(int a, int b)
{
	return (a * b);
}

int		ft_div(int a, int b)
{
	return (a / b);
}

int		ft_mod(int a, int b)
{
	return (a % b);
}
