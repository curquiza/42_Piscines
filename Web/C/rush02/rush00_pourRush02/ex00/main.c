/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/04 20:33:40 by curquiza          #+#    #+#             */
/*   Updated: 2016/08/20 13:02:22 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	colle(int x, int y);

int		main(int argc, char **argv)
{
	if (argc != 3)
		return (0);
	colle(atoi(argv[1]), atoi(argv[2]));
	return (0);
}
