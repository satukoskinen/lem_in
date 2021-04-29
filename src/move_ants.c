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

static int	move_ants_in_path(t_array *path, char **line, int ants_per_path,
int ant_count)
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
			if (prev->is_source && ants_per_path == 0)
				return (0);
			else if (prev->is_source && ants_per_path > 0)
				ants_per_path--;
			vertex->value = prev->value;
			if (prev->is_source && prev->value != ant_count)
				prev->value = prev->value + 1;
			else
				prev->value = 0;
			*line = add_move_to_line(*line, vertex->value, vertex->id);
			if (*line == NULL)
				return (-1);
		}
		j++;
	}
	return (ants_per_path);
}

int	move_ants(t_graph *graph, t_array *paths, int *ants_per_path,
t_array **output)
{
	char		*line;
	t_array		*path;
	int			ant_count;
	size_t		i;

	ant_count = graph->source->value;
	graph->source->value = 1;
	while (1)
	{
		line = NULL;
		i = 0;
		while (i < array_size(paths))
		{
			path = *(t_array **)array_get(paths, i);
			ants_per_path[i] = move_ants_in_path(path, &line,
				ants_per_path[i], ant_count);
			if (ants_per_path[i] == -1)
				return (0);
			i++;
		}
		if (line == NULL)
			break ;
		if (array_add(output, &line) == NULL)
		{
			free(line);
			return (0);
		}
	}
	return (1);
}

// int	move_ants(t_graph *graph, t_array *shortest_path, 
//t_array *max_flow_paths,
// t_array **output)
// {
// 	char		*line;
// 	t_array		*path;
// 	int			*ants_per_path;
// 	int			ant_count;
// 	size_t		i;

// 	ant_count = graph->source->value;
// 	ants_per_path = get_ants_per_path(ant_count, shortest_path,
// max_flow_paths);
// 	if (ants_per_path == NULL)
// 		return (0);
// 	if (ants_per_path[0] == ant_count)
// 	{
// 		max_flow_paths = shortest_path;
// 		ants_per_path[1] = ants_per_path[0];
// 	}
// 	graph->source->value = 1;
// 	while (1)
// 	{
// 		line = NULL;
// 		i = 0;
// 		while (i < array_size(max_flow_paths))
// 		{
// 			path = *(t_array **)array_get(max_flow_paths, i);
// 			ants_per_path[i + 1] = move_ants_in_path(path, &line, 
//ants_per_path[i + 1], ant_count);
// 			if (ants_per_path[i + 1] == -1)
// 				return (0);
// 			i++;
// 		}
// 		if (line == NULL)
// 			break ;
// 		array_add(output, &line);
// 	}
// 	return (1);
// }
