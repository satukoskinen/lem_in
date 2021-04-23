#include <stdlib.h>
#include "lem_in.h"
#include "libft.h"

static void	print_paths(t_array *paths)
{
	t_array		*path;
	t_vertex	*vertex;
	size_t		i;
	size_t		j;

	ft_printf("number of paths: %d\n", array_size(paths));
	i = 0;
	while (i < array_size(paths))
	{
		path = *(t_array **)array_get(paths, i);
		ft_printf("path %d: size %d\n", i, array_size(path));
		j = 0;
		while (j < array_size(path))
		{
			vertex = *(t_vertex **)array_get(path, j);
			ft_printf("vertex %d: id %s\n", j, vertex->id);
			j++;
		}
		i++;
	}
}

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
	if (PRINT_DEBUG)
	{
		print_paths(shortest_paths);
		print_paths(max_flow_paths);
	}
	ants_per_path = optimize_path_use(graph->source->value,
			shortest_paths, max_flow_paths, &paths_to_use);
	move_ants(graph, paths_to_use, ants_per_path, output);
	free_array(&shortest_paths);
	free_array(&max_flow_paths);
	return (1);
}
