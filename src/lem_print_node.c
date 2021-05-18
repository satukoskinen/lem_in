#include "lem_in.h"

/*
 *	Print a node and its incoming and outgoing edges.
 */

ssize_t	lem_print_node(void *data, size_t i)
{
	t_graph_node	*tmp;
	t_node_attr		*attr;

	tmp = data;
	attr = tmp->attr;
	print("key [%s] value [%d]\n",
		tmp->key, attr->value);
	parr_iter(&tmp->in, lem_print_edge);
	parr_iter(&tmp->out, lem_print_edge);
	return ((ssize_t)i);
}
