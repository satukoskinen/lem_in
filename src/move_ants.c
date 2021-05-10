#include "lem_in.h"
#include <stdlib.h>

static void	add_move_to_line(char **line, int ant, const char *node_key)
{
	char		*move;
	char		*new;

	ft_asprintf(&move, "L%d-%s ", ant, node_key);
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

static void	move_ant_from_prev(t_node_attr *prev_attr, t_node_attr *node_attr)
{
	node_attr->value = prev_attr->value;
	prev_attr->value = 0;
}

static int	move_ant_from_source(t_node_attr *src_attr,
	t_node_attr *node_attr, int ants_per_path, int ant_count)
{
	node_attr->value = src_attr->value;
	if (src_attr->value < ant_count)
		src_attr->value++;
	else
		src_attr->value = 0;
	return (ants_per_path - 1);
}

static int	move_ants_in_path(t_parray *path,
	char **line, int ants_per_path, int ant_count)
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
			else if (j + 1 == path->len - 1 && ants_per_path > 0)
				ants_per_path = move_ant_from_source(prev->attr,
						node->attr, ants_per_path, ant_count);
			else
				move_ant_from_prev(prev->attr, node->attr);
			add_move_to_line(line, ((t_node_attr *)node->attr)->value, node->key);
			if (*line == NULL)
				return (-1);
		}
		j++;
	}
	return (ants_per_path);
}

int	save_round_to_line(char **line, t_array *paths,
	int *ants_per_path, int ant_count)
{
	t_parray		*path;
	size_t			i;

	i = 0;
	while (i < paths->len)
	{
		path = arr_get(paths, i);
		ants_per_path[i] = move_ants_in_path(path, line,
				ants_per_path[i], ant_count);
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
	int				ant_count;
	char			*line;

	source = ((t_graph_attr *)graph->attr)->source;
	ant_count = ((t_node_attr *)source->attr)->value;
	((t_node_attr *)source->attr)->value = 1;
	while (1)
	{
		line = NULL;
		if (!save_round_to_line(&line, paths, ants_per_path, ant_count))
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