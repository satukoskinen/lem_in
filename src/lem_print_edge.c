#include "lem_in.h"

/*
 *	Print an edge, its flow and capacity.
 */

t_ssize	lem_print_edge(void *data, t_size i)
{
	t_graph_edge	*tmp;
	t_edge_attr		*attr;

	tmp = data;
	attr = tmp->attr;
	print("%-10s -> %-10s F = %d, C = %d\n",
		tmp->u->key, tmp->v->key, attr->flow, attr->capacity);
	return ((t_ssize)i);
}
