/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 14:35:52 by curquiza          #+#    #+#             */
/*   Updated: 2016/08/22 19:15:57 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int			ft_list_size(t_list *begin_list)
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

void		ft_list_reverse(t_list **begin_list)
{
	t_list	*end;
	t_list	*current;
	int		size;
	int		i;

	i = 0;
	if (*begin_list != 0)
	{
		size = ft_list_size(*begin_list);
		end = ft_list_at(*begin_list, size - 1);
		end->next = *begin_list;
		*begin_list = end;
		current = *begin_list;
		while (i < size - 2)
		{
			end = ft_list_at(*begin_list, size - 1);
			end->next = current->next;
			current->next = end;
			current = current->next;
			i++;
		}
		end = ft_list_at(*begin_list, size - 1);
		end->next = 0;
	}
}
