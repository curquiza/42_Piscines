/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/04 20:33:40 by curquiza          #+#    #+#             */
/*   Updated: 2016/08/06 23:30:19 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_recursive_power(int nb, int power);

int		main(void)
{
	printf("%d\n", ft_recursive_power(0, 0));
	printf("%d\n", ft_recursive_power(1, 2));
	printf("%d\n", ft_recursive_power(4, 0));
	printf("%d\n", ft_recursive_power(8, -1));
	printf("%d\n", ft_recursive_power(2, 3));
	printf("%d\n", ft_recursive_power(1222, 1));
	printf("%d\n", ft_recursive_power(-12, 3));
	printf("%d\n", ft_recursive_power(-1114552, 1245452));
	return (0);
}
