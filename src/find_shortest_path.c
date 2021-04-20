#include "graph.h"
#include "libft.h"

int	check_adjacent_vertices(t_array *queue, t_vertex *vertex, t_vertex *dst)
{
	t_edge	*adjacent_edge;
	size_t		i;

	i = 0;
	while (i < array_size(vertex->adj_list))
	{
		adjacent_edge = *(t_edge **)array_get(vertex->adj_list, i);
		if (adjacent_edge->dst->dist == -1)
		{
			adjacent_edge->dst->dist = vertex->dist + 1;
			adjacent_edge->dst->prev = vertex;
			if (ft_strcmp(adjacent_edge->dst->id, dst->id) == 0)
				return (1);
			array_add(&queue, &adjacent_edge->dst);
		}
		i++;
	}
	return (0);
}

int	find_shortest_path(t_graph *graph, t_vertex *src, t_vertex *dst)
{
	t_array		*queue;
	t_vertex	*vertex;
	int			reached_dst;

	queue = array_new(graph->vertex_count, sizeof(t_vertex *));
	if (queue == NULL)
		return (0);
	src->dist = 0;
	src->prev = NULL;
	array_add(&queue, &src);
	while (array_size(queue) > 0)
	{
		vertex = *(t_vertex **)array_get(queue, 0);
		array_remove(queue, 0);
		reached_dst = check_adjacent_vertices(queue, vertex, dst);
		if (reached_dst)
			break ;
	}
	array_del(&queue);
	return (dst->dist);
}
