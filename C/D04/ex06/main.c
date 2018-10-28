/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/04 20:33:40 by curquiza          #+#    #+#             */
/*   Updated: 2016/08/08 16:26:52 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_is_prime(int nb);

void	ft_putnbr(int nb);

int		main(void)
{
	//printf("%d\n", 2147483647);
	ft_putnbr(ft_is_prime(2147483647));
	printf("%d\n", ft_is_prime(12));
	printf("%d\n", ft_is_prime(0));
	printf("%d\n", ft_is_prime(1));
	printf("%d\n", ft_is_prime(2));
	printf("%d\n", ft_is_prime(4));
	printf("%d\n", ft_is_prime(13));
//	printf("%d\n", ft_is_prime(2147483647));
	return (0);
}
