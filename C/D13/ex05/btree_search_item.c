/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 21:53:48 by curquiza          #+#    #+#             */
/*   Updated: 2016/08/25 15:53:47 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdlib.h>

void	*btree_search_item(t_btree *root, void *data_ref,
			int (*cmpf)(void *, void *))
{
	void *result;

	if (root)
	{
		if (root->left)
			if ((result = btree_search_item(root->left, data_ref, (*cmpf))))
				return (result);
		if ((*cmpf)(root->item, data_ref) == 0)
			return (root->item);
		if (root->right)
			if ((result = btree_search_item(root->right, data_ref, (*cmpf))))
				return (result);
	}
	return (NULL);
}
