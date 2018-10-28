/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/04 20:23:10 by curquiza          #+#    #+#             */
/*   Updated: 2016/08/04 20:23:20 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int		buffer_a;
	int		buffer_b;

	buffer_a = *a;
	buffer_b = *b;
	*a = buffer_a / buffer_b;
	*b = buffer_a % buffer_b;
}
