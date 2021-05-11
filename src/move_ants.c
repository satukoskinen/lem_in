#include "lem_in.h"
#include <stdlib.h>

static void	move_to_line(char **line, int ant, const char *node_key)
{
	char	*move;
	char	*new;

	move = format("L%d-%s ", ant, node_key);
	if (move == NULL)
	{
		free(*line);
		*line = NULL;
	}
	new = s_join(*line, move);
	free(move);
	free(*line);
	*line = new;
}

static void	move_ant(t_node_attr *src_attr,
	t_node_attr *dst_attr, int ants, int prev_is_source)
{
	dst_attr->value = src_attr->value;
	if (prev_is_source && src_attr->value < ants)
		src_attr->value++;
	else
		src_attr->value = 0;
}

static int	move_ants_in_path(t_parray *path,
	char **line, int ants_per_path, int ants)
{
	t_graph_node	*node;
	t_graph_node	*prev;
	size_t			j;

	j = 0;
	while (j < path->len - 1)
	{
		node = parr_get(path, j);
		prev = parr_get(path, j + 1);
		if (((t_node_attr *)prev->attr)->value != 0)
		{
			if (j + 1 == path->len - 1 && ants_per_path == 0)
				return (0);
			else if (j + 1 == path->len - 1 && ants_per_path-- > 0)
				move_ant(prev->attr, node->attr, ants, 1);
			else
				move_ant(prev->attr, node->attr, ants, 0);
			move_to_line(line, ((t_node_attr *)node->attr)->value, node->key);
			if (*line == NULL)
				return (-1);
		}
		j++;
	}
	return (ants_per_path);
}

int	save_round_to_line(char **line, t_array *paths,
	int *ants_per_path, int ants)
{
	t_parray	*path;
	size_t		i;

	i = 0;
	while (i < paths->len)
	{
		path = arr_get(paths, i);
		ants_per_path[i] = move_ants_in_path(path, line,
				ants_per_path[i], ants);
		if (ants_per_path[i] == -1)
			return (-1);
		i++;
	}
	return (1);
}

int	move_ants(t_graph *graph, t_array *paths, int *ants_per_path,
	t_parray *output)
{
	t_graph_node	*source;
	int				ants;
	char			*line;

	source = ((t_graph_attr *)graph->attr)->source;
	ants = ((t_node_attr *)source->attr)->value;
	((t_node_attr *)source->attr)->value = 1;
	while (1)
	{
		line = NULL;
		if (!save_round_to_line(&line, paths, ants_per_path, ants))
			return (-1);
		if (line == NULL)
			break ;
		if (!parr_add_last(output, line))
		{
			free(line);
			return (-1);
		}
	}
	return (1);
}
