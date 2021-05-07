#include "lem_in.h"
#include "libft.h"
#include <stdlib.h>

static char	*add_move_to_line(char *line, int ant, const char *node_key)
{
	char		*move;
	char		*new;

	ft_asprintf(&move, "L%d-%s ", ant, node_key);
	new = ft_strjoin(line, move);
	free(move);
	free(line);
	return (new);
}

static int	move_ants_in_path(t_parray *path, char **line, int ants_per_path,
int ant_count)
{
	t_graph_node	*node;
	t_graph_node	*prev;
	t_node_attr		*node_attr;
	t_node_attr		*prev_attr;
	size_t			j;

	j = 0;
	while (j < path->len - 1)
	{
		node = parr_get(path, j);
		prev = parr_get(path, j + 1);
		node_attr = (t_node_attr *)node->attr;
		prev_attr = (t_node_attr *)prev->attr;
		if (prev_attr->value != 0)
		{
			if (j + 1 == path->len - 1 && ants_per_path == 0)
				return (0);
			else if (j + 1 == path->len - 1 && ants_per_path > 0)
				ants_per_path--;
			node_attr->value = prev_attr->value;
			if (j + 1 == path->len - 1 && prev_attr->value != ant_count)
				prev_attr->value++;
			else
				prev_attr->value = 0;
			*line = add_move_to_line(*line, node_attr->value, node->key);
			if (*line == NULL)
				return (-1);
		}
		j++;
	}
	return (ants_per_path);
}

int	move_ants(t_graph *graph, t_array *paths, int *ants_per_path,
t_parray *output)
{
	t_graph_node	*source;
	char			*line;
	t_parray		*path;
	int				ant_count;
	size_t			i;

	source = ((t_graph_attr *)graph->attr)->source;
	ant_count = ((t_node_attr *)source->attr)->value;
	((t_node_attr *)source->attr)->value = 1;
	while (1)
	{
		line = NULL;
		i = 0;
		while (i < paths->len)
		{
			path = arr_get(paths, i);
			ants_per_path[i] = move_ants_in_path(path, &line,
					ants_per_path[i], ant_count);
			if (ants_per_path[i] == -1)
				return (-1);
			i++;
		}
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
