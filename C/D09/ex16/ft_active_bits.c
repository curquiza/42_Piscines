/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_active_bits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 12:45:19 by curquiza          #+#    #+#             */
/*   Updated: 2016/08/12 12:53:13 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb * ft_recursive_power(nb, power - 1));
}

unsigned int	ft_active_bits(int value)
{
	int				i;
	unsigned int	count;

	i = 31;
	count = 0;
	while (i >= 0)
	{
		if (value >= ft_recursive_power(2, i))
		{
			value = value - ft_recursive_power(2, i);
			count++;
		}
		i--;
	}
	return (count);
}
