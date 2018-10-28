/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/19 10:23:48 by curquiza          #+#    #+#             */
/*   Updated: 2016/08/19 10:42:33 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int		ft_list_size(t_list *begin_list)
{
	int		cpt;

	cpt = 0;
	while (begin_list != 0)
	{
		cpt++;
		begin_list = begin_list->next;
	}
	return (cpt);
}
