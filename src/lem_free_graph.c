#include "lem_in.h"
#include <stdlib.h>

ssize_t free_edge(void *data, size_t i)
{
	t_graph_edge	*edge;

	edge = data;
	free(edge->attr);
	return ((ssize_t)i);
}

ssize_t free_node(void *data, size_t i)
{
	t_graph_node	*node;
	t_node_attr		*attr;

	node = data;
	attr = node->attr;
	free(attr->name);
	free(attr);
	arr_iter(&node->in, free_edge);
	arr_free(&node->in);
	arr_free(&node->out);
	free(node);
	return ((ssize_t)i);
}

void	lem_free_graph(t_graph *graph)
{
	free(graph->attr);
	map_iter(&graph->data, free_node);
	map_free(&graph->data);
}
