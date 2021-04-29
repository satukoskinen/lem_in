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
	t_array	*shortest_paths;
	t_array	*max_flow_paths;
	t_array	*all_simple_paths;
	t_array	*simple_path_combinations;
	t_array	*paths_to_use;
	int		*ants_per_path;

	shortest_paths = get_shortest_paths(graph);
	if (shortest_paths == NULL)
		return (-1);
	max_flow_paths = get_max_flow_paths(graph);
	if (max_flow_paths == NULL)
	{
		free_array(&shortest_paths);
		return (-1);
	}
	all_simple_paths = find_all_simple_paths(graph, graph->source, graph->sink);
	if (all_simple_paths == NULL)
		return (-1);
	simple_path_combinations = get_shortest_path_combinations(graph, all_simple_paths, max_flow_paths);
	if (simple_path_combinations == NULL)
	{
		ft_printf("error");
		return (-1);
	}
	if (PRINT_DEBUG)
	{
//		print_paths(shortest_paths);
//		print_paths(max_flow_paths);
//		print_paths(all_simple_paths);
//		print_paths(simple_path_combinations);
	}
	ants_per_path = optimize_path_use(graph->source->value,
			shortest_paths, max_flow_paths, simple_path_combinations, &paths_to_use);
	if (ants_per_path == NULL)
	{
		free_array(&shortest_paths);
		free_array(&max_flow_paths);
		return (-1);
	}
	print_paths(paths_to_use);
	move_ants(graph, paths_to_use, ants_per_path, output);
	free(ants_per_path);
	free_array(&shortest_paths);
	free_array(&max_flow_paths);
	return (1);
}
