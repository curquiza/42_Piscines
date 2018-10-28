#include "ft_btree.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void	btree_insert_data(t_btree **root, void *tem, int (*cmpf)(void *, void *));
int		ft_strcmp(void *, void *);
void	ft_putstr(void *str);

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

int		main(void)
{
	t_btree		*tree;

	tree = 0;
	btree_insert_data(&tree, "2", &ft_strcmp);
	btree_insert_data(&tree, "3", &ft_strcmp);
	//btree_insert_data(&tree, "4", &ft_strcmp);
	btree_insert_data(&tree, "1", &ft_strcmp);
	//btree_insert_data(&tree, "0", &ft_strcmp);
	//btree_insert_data(&tree, "1", &ft_strcmp);
	//btree_insert_data(&tree, "2", &ft_strcmp);
	//btree_insert_data(&tree, "6", &ft_strcmp);

	btree_apply_infix(tree, &ft_putstr);
	write(1, "\n", 1);
	printf("%d", btree_level_count(tree));
}
