#include "lem_in.h"

ssize_t	lem_compare_nodes(t_graph_node *n1, t_graph_node *n2)
{
	if (s_cmp(n1->key, n2->key) == 0)
		return (1);
	return (0);
}
