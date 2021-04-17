#include "lem_in.h"
#include "libft.h"
#include <stdlib.h>

static char	*add_move_to_line(char *line, int ant, char *vertex_id)
{
	char		*move;
	char		*new;

	ft_asprintf(&move, "L%d-%s ", ant, vertex_id);
	new = ft_strjoin(line, move);
	free(move);
	free(line);
	return (new);
}

static int	move_ants_in_path(t_array *path, char **line, int ant_count)
{
	t_vertex	*vertex;
	t_vertex	*prev;
	size_t		j;

	j = 0;
	while (j < array_size(path) - 1)
	{
		vertex = *(t_vertex **)array_get(path, j);
		prev = *(t_vertex **)array_get(path, j + 1);
		if (prev->value != 0)
		{
			vertex->value = prev->value;
			if (j != array_size(path) - 2)
				prev->value = 0;
			else
				prev->value = prev->value + 1;
			*line = add_move_to_line(*line, vertex->value, vertex->id);
			if (*line == NULL)
				return (0);
		}
		if (prev->value > ant_count)
			prev->value = 0;
		j++;
	}
	return (1);
}

int	move_ants(t_graph *graph, t_array *shortest_path, t_array *max_flow_paths,
t_array **output)
{
	char		*line;
	t_array		*path;
	int			ant_count;
	size_t		i;

	if (graph->source->value == 1)
		max_flow_paths = shortest_path;
	ant_count = graph->source->value;
	graph->source->value = 1;
	while (1)
	{
		line = NULL;
		i = 0;
		while (i < array_size(max_flow_paths))
		{
			path = *(t_array **)array_get(max_flow_paths, i);
			move_ants_in_path(path, &line, ant_count);
			i++;
		}
		if (line == NULL)
			break ;
		array_add(output, &line);
	}
	return (1);
}
