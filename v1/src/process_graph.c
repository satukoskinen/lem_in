#include <stdlib.h>
#include "lem_in.h"
#include "libft.h"

static void	free_array(t_array **arr)
{
	size_t	i;

	i = 0;
	while (i < array_size(*arr))
	{
		array_del((t_array **)array_get(*arr, i));
		i++;
	}
	array_del(arr);
}

int	process_graph(t_graph *graph, t_array **output)
{
	t_array	*max_flow_paths;
	t_array	*paths_to_use;
	int		*ants_per_path;

	max_flow_paths = get_max_flow_paths(graph);
	if (max_flow_paths == NULL)
		return (-1);
	if (PRINT_DEBUG)
	{
		size_t i = 0;
		while (i < array_size(max_flow_paths))
		{
			print_paths(*(t_array **)array_get(max_flow_paths, i));
			i++;
		}
	}
	ants_per_path = optimize_path_use(graph->source->value, max_flow_paths, &paths_to_use);
	if (ants_per_path == NULL)
	{
		free_array(&max_flow_paths);
		return (-1);
	}
	if (PRINT_DEBUG)
		print_paths(paths_to_use);
	move_ants(graph, paths_to_use, ants_per_path, output);
	free(ants_per_path);
	free_array(&max_flow_paths);
	return (1);
}
