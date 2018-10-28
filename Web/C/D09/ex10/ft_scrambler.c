/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scrambler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 15:33:14 by curquiza          #+#    #+#             */
/*   Updated: 2016/08/12 15:42:39 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	f_scrambler(int ***a, int *b, int *******c, int ****d)
{
	int		buffer_a;
	int		buffer_b;
	int		buffer_c;
	int		buffer_d;

	buffer_a = ***a;
	buffer_b = *b;
	buffer_c = *******c;
	buffer_d = ****d;
	*******c = buffer_a;
	****d = buffer_c;
	*b = buffer_d;
	***a = buffer_b;
}
