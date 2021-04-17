#include "lem_in.h"
#include "libft.h"
#include <stdlib.h>

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

static t_array	*get_shortest_path(t_graph *graph)
{
	int		shortest_path_len;
	t_array	*shortest_path;

	shortest_path_len = find_shortest_path(graph, graph->source, graph->sink);
	if (shortest_path_len == -1)
		return (NULL);
	shortest_path = save_paths(graph, graph->source, graph->sink, 1);
	return (shortest_path);
}

static t_array	*get_max_flow_paths(t_graph *graph)
{
	int		max_flow;
	t_array	*max_flow_paths;

	max_flow = max_flow_edmonds_karp(graph, graph->source, graph->sink);
	if (max_flow <= 0)
		return (NULL);
	max_flow_paths = save_paths(graph, graph->source, graph->sink, max_flow);
	return (max_flow_paths);
}

int	process_graph(t_graph *graph, t_array **output)
{
	t_array	*shortest_path;
	t_array	*max_flow_paths;

	shortest_path = get_shortest_path(graph);
	if (shortest_path == NULL)
		return (-1);
	max_flow_paths = get_max_flow_paths(graph);
	if (max_flow_paths == NULL)
	{
		free_array(&shortest_path);
		return (-1);
	}
	print_paths(shortest_path);
	print_paths(max_flow_paths);
	move_ants(graph, shortest_path, max_flow_paths, output);
	free_array(&shortest_path);
	free_array(&max_flow_paths);
	return (1);
}
