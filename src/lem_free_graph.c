#include "lem_in.h"
#include <stdlib.h>

static ssize_t	free_edge(void *data, size_t i)
{
	t_graph_edge	*edge;

	edge = data;
	free(edge->attr);
	free(edge);
	return ((ssize_t)i);
}

static ssize_t	free_node(void *data, size_t i)
{
	t_graph_node	*node;
	t_node_attr		*attr;

	node = data;
	attr = node->attr;
	free(attr->name);
	free(attr);
	parr_iter(&node->in, free_edge);
	parr_free(&node->in);
	parr_free(&node->out);
	free(node);
	return ((ssize_t)i);
}

void	lem_free_graph(t_graph *graph)
{
	map_iter(graph, free_node);
	map_free(graph);
}
