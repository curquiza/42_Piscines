/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/19 12:38:51 by curquiza          #+#    #+#             */
/*   Updated: 2016/08/19 13:46:38 by curquiza         ###   ########.fr       */
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

t_list		*ft_list_push_params(int ac, char **av)
{
	int		i;
	t_list	*begin_list;

	begin_list = ft_create_elem(av[0]);
	i = 1;
	while (i < ac)
	{
		ft_list_push_front(&begin_list, av[i]);
		i++;
	}
	return (begin_list);
}
