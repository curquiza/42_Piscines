/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 13:02:02 by curquiza          #+#    #+#             */
/*   Updated: 2016/08/24 18:44:15 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <unistd.h>
#include <stdio.h>

void	btree_insert_data(t_btree **root, void *item,
							int (*cmpf)(void *, void *))
{
	if (!(*root))
		*root = btree_create_node(item);
	else
	{
		if ((*cmpf)((*root)->item, item) <= 0)
		{
			if ((*root)->right)
				btree_insert_data(&((*root)->right), item, cmpf);
			else
				(*root)->right = btree_create_node(item);
		}
		else
		{
			if ((*root)->left)
				btree_insert_data(&((*root)->left), item, cmpf);
			else
				(*root)->left = btree_create_node(item);
		}
	}
}
