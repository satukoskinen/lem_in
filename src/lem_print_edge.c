#include "lem_in.h"

/*
 *	Print an edge, its flow and capacity.
 */

ssize_t	lem_print_edge(void *data, size_t i)
{
	t_graph_edge	*tmp;
	t_edge_attr		*attr;

	tmp = data;
	attr = tmp->attr;
	print("%-10s -> %-10s F = %d, C = %d\n",
		tmp->u->key, tmp->v->key, attr->flow, attr->capacity);
	return ((ssize_t)i);
}
