#include "lem_in.h"

ssize_t	lem_compare_nodes(t_graph_node *n1, t_graph_node *n2)
{
	if (n1->id == n2->id)
		return (1);
	return (0);
}
