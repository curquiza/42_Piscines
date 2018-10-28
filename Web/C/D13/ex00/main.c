#include "ft_btree.h"
#include <stdlib.h>

int		ft_strcmp(void *, void *);

int		main(void)
{
	t_btree		*tree;

	//tree = (t_btree*)malloc(sizeof(t_btree));
	tree = btree_create_node("TEST");
}
