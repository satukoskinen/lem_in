#include "lem_in.h"

ssize_t	lem_edge_remaining_capacity(t_graph_edge *edge)
{
	t_edge_attr	*attr;

	attr = (t_edge_attr *)edge->attr;
	return (attr->capacity - attr->flow);
}
