/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/19 22:35:26 by curquiza          #+#    #+#             */
/*   Updated: 2016/08/19 22:57:11 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list		*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	t_list			*current;
	unsigned int	cpt;

	cpt = 0;
	current = begin_list;
	while (cpt < nbr && current != 0)
	{
		current = current->next;
		cpt++;
	}
	if (cpt == nbr)
		return (current);
	else
		return (0);
}
