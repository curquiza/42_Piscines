/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_infix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 23:27:27 by curquiza          #+#    #+#             */
/*   Updated: 2016/08/24 20:17:38 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_apply_infix(t_btree *root, void (*applyf)(void*))
{
	if (root != 0)
	{
		if (root->left)
			btree_apply_infix(root->left, applyf);
		(applyf)(root->item);
		if (root->right)
			btree_apply_infix(root->right, applyf);
	}
}
