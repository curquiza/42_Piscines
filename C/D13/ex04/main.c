#include "ft_btree.h"
#include <stdlib.h>

int		ft_strcmp(void *, void *);

int		main(void)
{
	t_btree		*tree;

	tree = 0;
	btree_insert_data(&tree, "2", &ft_strcmp);
	btree_insert_data(&tree, "3", &ft_strcmp);
	btree_insert_data(&tree, "4", &ft_strcmp);
	btree_insert_data(&tree, "1", &ft_strcmp);
	btree_insert_data(&tree, "0", &ft_strcmp);
	btree_insert_data(&tree, "1", &ft_strcmp);
}
