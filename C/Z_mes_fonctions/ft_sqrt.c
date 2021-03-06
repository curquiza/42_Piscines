/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 19:16:12 by curquiza          #+#    #+#             */
/*   Updated: 2016/08/08 17:19:45 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	long		i;

	i = 0;
	while (i * i != nb && i * i < nb)
		i++;
	if (i * i != nb)
		return (0);
	else
		return (i);
}
