#include "graph.h"
#include "libft.h"
#include <stdlib.h>

int	graph_contains_edge(t_vertex *src, t_vertex *dst)
{
	if (src->adj_list == NULL || graph_get_edge(src, dst) == NULL)
		return (0);
	else
		return (1);
}

static t_edge	*edge_new(t_vertex *src, t_vertex *dst, int capacity)
{
	t_edge	*edge;

	edge = (t_edge *)malloc(sizeof(t_edge));
	if (edge == NULL)
		return (NULL);
	edge->src = src;
	edge->dst = dst;
	edge->flow = 0;
	edge->capacity = capacity;
	edge->reverse_edge = NULL;
	return (edge);
}

static int	graph_add_one_edge(t_graph *graph, t_vertex *v1,
t_vertex *v2, int capacity)
{
	t_edge	*edge;

	if (v1 == NULL || v2 == NULL)
		return (0);
	if (graph_contains_edge(v1, v2))
		return (0);
	edge = edge_new(v1, v2, capacity);
	if (edge == NULL)
		return (-1);
	if (v1->adj_list == NULL)
	{
		v1->adj_list = array_new(INIT_SIZE, sizeof(t_edge *));
		if (v1->adj_list == NULL)
			return (-1);
	}
	array_add(&v1->adj_list, &edge);
	if (v1->adj_list == NULL)
		return (-1);
	array_add(&graph->edges, &edge);
	if (graph->edges == NULL)
		return (-1);
	graph->edge_count += 1;
	return (1);
}

int	graph_add_inner_edge(t_graph *graph, char *id, int capacity)
{
	t_vertex	*v;
	int			ret;

	v = graph_get_vertex(graph, id);
	if (v == NULL)
		return (0);
	ret = graph_add_one_edge(graph, v->in, v->out, capacity);
	if (ret != 1)
		return (ret);
	ret = graph_add_one_edge(graph, v->out, v->in, 0);
	if (ret != 1)
		return (ret);
	return (1);
}

int	graph_add_edge(t_graph *graph, char *v1_id, char *v2_id, int capacity)
{
	t_vertex	*v1;
	t_vertex	*v2;
	int			ret;

	v1 = graph_get_vertex(graph, v1_id);
	v2 = graph_get_vertex(graph, v2_id);
	if (v1 == NULL || v2 == NULL)
		return (0);
	ret = graph_add_one_edge(graph, v1, v2, capacity);
	if (ret == -1)
		return (-1);
	ret = graph_add_one_edge(graph, v1->out, v2->in, capacity);
	if (ret != 1)
		return (ret);
	ret = graph_add_one_edge(graph, v2->in, v1->out, 0);
	if (ret != 1)
		return (ret);
	return (1);
}
