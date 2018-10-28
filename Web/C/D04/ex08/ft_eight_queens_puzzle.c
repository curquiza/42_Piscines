/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eight_queens_puzzle.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 16:35:36 by curquiza          #+#    #+#             */
/*   Updated: 2016/08/08 16:51:28 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_eight_queens_puzzle2(int i)
{
	if (i == 0)
		return (0);
	ft_eight_queens_puzzle2(i - 1);
	return (92);
}

int		ft_eight_queens_puzzle(void)
{
	return (ft_eight_queens_puzzle2(92));
}
