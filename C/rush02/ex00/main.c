/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/20 22:16:19 by curquiza          #+#    #+#             */
/*   Updated: 2016/08/21 11:54:29 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>
#include "colle_2.h"
#include "ft_basic.h"

#include "ft_init_colle.h"

char	*ft_read(void)
{
	char	*buf;
	char	text[SIZE + 1];
	int		ret;

	ret = 0;
	buf = (char *)malloc(sizeof(char) * (SIZE_BUF + 1));
	while ((ret = read(0, text, SIZE)) != 0)
	{
		text[ret] = '\0';
		buf = ft_strcat(buf, text);
	}
	return (buf);
}

int		main(void)
{
	char	*buf;
	t_colle	colle_buf;
	char	**all_colles;

	buf = ft_read();
	if (ft_strcmp(buf, "\0") == 0)
	{
		ft_putstr("aucune\n");
		return (0);
	}
	ft_calc_row_col(&colle_buf, buf);
	all_colles = ft_complete_all_colles(colle_buf.nb_col, colle_buf.nb_row);
	ft_find_colle(buf, all_colles, colle_buf.nb_col, colle_buf.nb_row);
	return (0);
}
