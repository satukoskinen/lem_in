#include "graph.h"
#include "libft.h"

void	graph_print_vertices(t_graph *graph)
{
	size_t		i;
	t_vertex	*vertex;

	i = 0;
	while (i < array_size(graph->vertices))
	{
		vertex = (t_vertex *)array_get(graph->vertices, i);
		ft_printf("id: %s value: %d\n", vertex->id, vertex->value);
		i++;
	}
	ft_printf("source: id: %s value: %d\n", graph->source->id, graph->source->value);
	ft_printf("sink: id: %s value: %d\n", graph->sink->id, graph->sink->value);
}

void	graph_print_edges(t_graph *graph)
{
	size_t		i;
	size_t		j;
	t_vertex	*vertex;
	t_vertex	*adj;

	i = 0;
	while (i < array_size(graph->vertices))
	{
		vertex = (t_vertex *)array_get(graph->vertices, i);
		j = 0;
		while (vertex->adj_list != NULL && j < array_size(vertex->adj_list))
		{
			adj = *(t_vertex **)array_get(vertex->adj_list, j);
			ft_printf("%s -> %s\n", vertex->id, adj->id);
			j++;
		}
		i++;
	}
}
