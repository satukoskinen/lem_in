#include "graph.h"
#include "libft.h"

void	graph_print_vertices(t_graph *graph)
{
	size_t		i;
	t_vertex	*vertex;

	i = 0;
	while (i < array_size(graph->vertices))
	{
		vertex = *(t_vertex **)array_get(graph->vertices, i);
		ft_printf("id: %s value: %d prev: %p\n",
			vertex->id, vertex->value, vertex->prev);
		i++;
	}
	ft_printf("source: id: %s value: %d\n",
		graph->source->id, graph->source->value);
	ft_printf("sink: id: %s value: %d\n",
		graph->sink->id, graph->sink->value);
}

void	graph_print_edges(t_graph *graph)
{
	size_t		i;
	t_edge		*edge;

	i = 0;
	while (i < array_size(graph->edges))
	{
		edge = *(t_edge **)array_get(graph->edges, i);
		ft_printf("%s -> %s, flow %d, capacity %d\n",
			edge->src->id, edge->dst->id, edge->flow, edge->capacity);
		i++;
	}
}
