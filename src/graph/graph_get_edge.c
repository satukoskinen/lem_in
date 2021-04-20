#include "graph.h"
#include "libft.h"

t_edge	*graph_get_edge_by_id(t_graph *graph, char *src_id, char *dst_id)
{
	t_edge	*edge;
	size_t	i;

	i = 0;
	while (i < array_size(graph->edges))
	{
		edge = *(t_edge **)array_get(graph->edges, i);
		if (ft_strcmp(edge->src->id, src_id) == 0
			&& ft_strcmp(edge->dst->id, dst_id) == 0)
			return (edge);
		i++;
	}
	return (NULL);
}

t_edge	*graph_get_edge(t_vertex *src, t_vertex *dst)
{
	t_edge	*edge;
	size_t	i;

	i = 0;
	while (i < array_size(src->adj_list))
	{
		edge = *(t_edge **)array_get(src->adj_list, i);
		if (ft_strcmp(edge->dst->id, dst->id) == 0)
			return (edge);
		i++;
	}
	return (NULL);
}
