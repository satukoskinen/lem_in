#include "graph.h"
#include "libft.h"
#include <stdlib.h>

int	graph_contains_edge(t_graph *graph, char *src_id, char *dst_id)
{
	t_edge	*edge;
	size_t	i;

	i = 0;
	while (i < array_size(graph->edges))
	{
		edge = (t_edge *)array_get(graph->edges, i);
		if (ft_strcmp(edge->src->id, src_id) == 0
			&& ft_strcmp(edge->dst->id, dst_id) == 0)
			return (1);
		i++;
	}
	return (0);
}

void	init_edge(t_edge *edge, t_vertex *src, t_vertex *dst, int capacity)
{
	edge->src = src;
	edge->dst = dst;
	edge->flow = 0;
	edge->capacity = capacity;
}

int	graph_add_edge(t_graph *graph, char *v1_id, char *v2_id, int capacity)
{
	t_vertex	*v1;
	t_vertex	*v2;
	t_edge		edge;

	v1 = graph_get_vertex(graph, v1_id);
	v2 = graph_get_vertex(graph, v2_id);
	if (v1 == NULL || v2 == NULL)
		return (0);
	if (graph_contains_edge(graph, v1->out->id, v2->in->id))
		return (0);
	if (v1->adj_list == NULL)
	{
		v1->adj_list = array_new(INIT_SIZE, sizeof(t_vertex *));
		if (v1->adj_list == NULL)
			return (-1);
	}
	array_add(&v1->adj_list, &v2);
	if (v1->adj_list == NULL)
		return (-1);
	init_edge(&edge, v1->out, v2->in, capacity);
	array_add(&graph->edges, &edge);
	if (graph->edges == NULL)
		return (-1);
	graph->edge_count += 1;
	return (1);
}
