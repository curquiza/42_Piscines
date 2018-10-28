/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/04 20:33:40 by curquiza          #+#    #+#             */
/*   Updated: 2016/08/07 19:15:36 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_fibonacci(int index);

int		main(void)
{
	printf("%d\n", ft_fibonacci(0));
	printf("%d\n", ft_fibonacci(1));
	printf("%d\n", ft_fibonacci(4));
	printf("%d\n", ft_fibonacci(8));
	printf("%d\n", ft_fibonacci(13));
	printf("%d\n", ft_fibonacci(46));
	printf("%d\n", ft_fibonacci(47));
	printf("%d\n", ft_fibonacci(45427));
	printf("%d\n", ft_fibonacci(-1114552));
	return (0);
}
