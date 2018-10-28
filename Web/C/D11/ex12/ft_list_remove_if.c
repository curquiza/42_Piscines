/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 09:58:28 by curquiza          #+#    #+#             */
/*   Updated: 2016/08/22 14:17:21 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_suppr_elem(t_list **elem)
{
	t_list	*suppr;

	suppr = *elem;
	*elem = (*elem)->next;
	free(suppr);
}

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*current;

	if (*begin_list != 0)
	{
		current = *begin_list;
		while (current->next != 0)
		{
			if ((*cmp)(current->next->data, data_ref) == 0)
				ft_suppr_elem(&(current->next));
			else
				current = current->next;
		}
		if (*begin_list != 0)
		{
			if ((*cmp)((*begin_list)->data, data_ref) == 0)
				ft_suppr_elem(begin_list);
		}
	}
}
