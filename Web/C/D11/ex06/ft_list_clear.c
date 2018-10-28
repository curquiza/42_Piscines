/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/19 14:13:15 by curquiza          #+#    #+#             */
/*   Updated: 2016/08/21 14:15:52 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void		ft_list_clear(t_list **begin_list)
{
	t_list		*suppr;
	t_list		*current;

	current = *begin_list;
	while (current != 0)
	{
		suppr = current;
		current = suppr->next;
		free(suppr);
	}
	*begin_list = NULL;
}
