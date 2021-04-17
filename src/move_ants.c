#include "lem_in.h"
#include "libft.h"
#include <stdlib.h>

int	move_ants(t_graph *graph, t_array *shortest_path, t_array *max_flow_paths, t_array **output)
{
	char 		*line;
	char		*move;
	char		*tmp;
	t_array		*path;
	t_vertex	*prev;
	t_vertex	*vertex;
	size_t		i;
	size_t		j;
	int			ant_count;

	if (graph->source->value == 1)
		max_flow_paths = shortest_path;
	ant_count = graph->source->value;
	graph->source->value = 1;
	move = NULL;
	while (1)
	{
		line = NULL;
		i = 0;
		while (i < array_size(max_flow_paths))
		{
			path = *(t_array **)array_get(max_flow_paths, i);
			j = 0;
			while (j < array_size(path) - 1)
			{
				vertex = *(t_vertex **)array_get(path, j);
				prev = *(t_vertex **)array_get(path, j + 1);
				if (prev->value != 0)
				{
					ft_asprintf(&move, "L%d-%s ", prev->value, vertex->id);
					vertex->value = prev->value;
					if (j != array_size(path) - 2)
						prev->value = 0;
					tmp = ft_strjoin(line, move);
					free(move);
					free(line);
					line = tmp;
				}
				if (j == array_size(path) - 2 && prev->value != 0)
					prev->value = prev->value + 1;
				if (prev->value > ant_count)
					prev->value = 0;
				j++;
			}
			i++;
		}
		if (line == NULL)
			break ;
		array_add(output, &line);
	}
	return (1);
}
