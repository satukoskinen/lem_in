#include "lem_in.h"
#include "libft.h"
#include <stdlib.h>

void	print_paths(t_array *paths)
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

void	free_arrays(t_array **arr_1, t_array **arr_2)
{
	size_t	i;

	i = 0;
	while (i < array_size(*arr_1))
	{
		array_del((t_array**)array_get(*arr_1, i));
		i++;
	}
	array_del(arr_1);
	i = 0;
	while (i < array_size(*arr_2))
	{
		array_del((t_array**)array_get(*arr_2, i));
		i++;
	}
	array_del(arr_2);
}

int	process_graph(t_graph *graph, t_array **output)
{
	int		shortest_path_length;
	int		max_flow;
	t_array	*shortest_path;
	t_array	*max_flow_paths;

	shortest_path_length = find_shortest_path(graph->source, graph->sink, NULL);
	if (shortest_path_length == -1)
		return (-1);
	shortest_path = save_paths(graph, graph->source, graph->sink, 1);
	if (shortest_path == NULL)
		return (-1);
	print_paths(shortest_path);
	max_flow = max_flow_edmonds_karp(graph->source, graph->sink, graph);
	if (max_flow <= 0)
		return (max_flow);
	max_flow_paths = save_paths(graph, graph->source, graph->sink, max_flow);
	if (max_flow_paths == NULL)
		return (-1);
	print_paths(max_flow_paths);
	move_ants(graph, shortest_path, max_flow_paths, output);
	free_arrays(&shortest_path, &max_flow_paths);
	return (1);
}
