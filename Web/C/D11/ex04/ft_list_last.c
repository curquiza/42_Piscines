/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/19 11:54:33 by curquiza          #+#    #+#             */
/*   Updated: 2016/08/19 12:23:41 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list		*ft_list_last(t_list *begin_list)
{
	if (begin_list == 0)
	{
		return (begin_list);
	}
	while (begin_list->next != 0)
	{
		begin_list = begin_list->next;
	}
	return (begin_list);
}
