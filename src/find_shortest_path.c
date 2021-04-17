#include "graph.h"
#include "libft.h"

int	check_adjacent_vertices(t_array *queue, t_vertex *vertex, t_vertex *dst)
{
	t_vertex	*adjacent;
	size_t		i;

	i = 0;
	while (i < array_size(vertex->adj_list))
	{
		adjacent = *(t_vertex **)array_get(vertex->adj_list, i);
		if (adjacent->dist == -1)
		{
			adjacent->dist = vertex->dist + 1;
			adjacent->prev = vertex;
			if (ft_strcmp(adjacent->id, dst->id) == 0)
				return (1);
			array_add(&queue, &adjacent);
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
