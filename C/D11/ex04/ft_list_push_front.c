/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 23:14:54 by curquiza          #+#    #+#             */
/*   Updated: 2016/08/19 10:00:18 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void		ft_list_push_front(t_list **begin_list, void *data)
{
	t_list		*new_list;

	if (*begin_list == 0)
		*begin_list = ft_create_elem(data);
	else
	{
		new_list = ft_create_elem(data);
		new_list->next = *begin_list;
		*begin_list = new_list;
	}
}
