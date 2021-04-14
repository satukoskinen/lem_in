#include "graph.h"
#include "libft.h"

int	save_path_to_output(t_vertex *vertex, t_array **output)
{
	while (vertex != NULL)
	{
		if (array_insert(output, &vertex->id, 0) == NULL)
			return (-1);
		vertex = vertex->prev;
	}
	return (1);
}

int	find_shortest_path(t_vertex *src, t_vertex *dst, t_array **output)
{
	t_array		*queue;
	t_vertex	*vertex;
	t_vertex	*adjacent;
	size_t		i;

	queue = array_new(INIT_SIZE, sizeof(t_vertex *));
	if (queue == NULL)
		return (0);
	src->dist = 0;
	if (array_add(&queue, &src) == NULL)
	{
		array_del(&queue);
		return (-1);
	}
	while (array_size(queue) > 0)
	{
		vertex = *(t_vertex **)array_get(queue, 0);
		array_remove(queue, 0);
		i = 0;
		while (i < array_size(vertex->adj_list))
		{
			adjacent = *(t_vertex **)array_get(vertex->adj_list, i);
			if (adjacent->prev == NULL)
			{
				adjacent->dist = vertex->dist + 1;
				adjacent->prev = vertex;
				if (ft_strcmp(adjacent->id, dst->id) == 0)
					break ;
				if (array_add(&queue, &adjacent) == NULL)
				{
					array_del(&queue);
					return (-1);
				}
			}
			i++;
		}
	}
	array_del(&queue);
	if (dst->dist == -1)
		return (-1);
	if (output != NULL)
		save_path_to_output(dst, output);
	return (dst->dist);
}