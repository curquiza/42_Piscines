/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/04 20:33:40 by curquiza          #+#    #+#             */
/*   Updated: 2016/08/08 17:21:26 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_sqrt(int nb);

int		main(void)
{
	//printf("%d\n", ft_sqrt(0));
	//printf("%d\n", ft_sqrt(1));
	printf("%d\n", ft_sqrt(-200));
	//printf("%d\n", ft_sqrt(8));
	//printf("%d\n", ft_sqrt(13));
	//printf("%d\n", ft_sqrt(46));
	//printf("%d\n", ft_sqrt(47));
	//printf("%d\n", ft_sqrt(45427));
	printf("%d\n", ft_sqrt(2147483647));
	//printf("%d\n", ft_sqrt(-1114552));
	return (0);
}
