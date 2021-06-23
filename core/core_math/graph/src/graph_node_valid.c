#include "../../../inc/core.h"

t_ssize	graph_node_valid(void *data, t_size i)
{
	t_graph_node	*n;

	n = data;
	n->valid = TRUE;
	return ((t_ssize)i);
}
