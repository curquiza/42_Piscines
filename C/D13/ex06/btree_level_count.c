/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 09:40:44 by curquiza          #+#    #+#             */
/*   Updated: 2016/08/25 10:44:09 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_btree.h"

int		btree_level_count(t_btree *root)
{
	int		count;

	count = 0;
	if (root == NULL)
		return (0);
	if (btree_level_count(root->left) > btree_level_count(root->right))
		return (count + 1 + btree_level_count(root->left));
	if (btree_level_count(root->left) <= btree_level_count(root->right))
		return (count + 1 + btree_level_count(root->right));
	return (1);
}
