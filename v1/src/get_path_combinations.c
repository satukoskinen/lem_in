#include "lem_in.h"
#include "libft.h"

int		path_is_vertex_disjoint(t_array *path)
{
	size_t		i;
	t_vertex	*vertex;

	i = 0;
	while (i < array_size(path))
	{
		vertex = *(t_vertex **)array_get(path, i);
		if (vertex->dist == 1 && !vertex->is_sink && !vertex->is_source)
			return (0);
		i++;
	}
	return (1);
}

static void	set_vertices_dist(t_array *array, int value)
{
	size_t		i;
	t_vertex	*vertex;

	i = 0;
	while (i < array_size(array))
	{
		vertex = *(t_vertex **)array_get(array, i);
		vertex->dist = value;
		i++;
	}
}

int	find_n_disjoint_paths(t_array *all_simple_paths, t_array **n_paths, size_t start_i, size_t end_i, size_t n)
{
	size_t	i;
	t_array	*path;

	if (array_size(*n_paths) == 0)
	{
		path = *(t_array **)array_get(all_simple_paths, end_i);
		set_vertices_dist(path, 1);
		array_add(n_paths, &path);
	}
	if (array_size(*n_paths) == n)
		return (1);
	i = start_i;
	while (i < end_i)
	{
		path = *(t_array **)array_get(all_simple_paths, i);
		if (path_is_vertex_disjoint(path))
		{
			set_vertices_dist(path, 1);
			array_add(n_paths, &path);
			if (find_n_disjoint_paths(all_simple_paths, n_paths, i + 1, end_i, n))
				return (1);
			set_vertices_dist(path, 0);
			array_remove(*n_paths, array_size(*n_paths) - 1);
		}
		i++;
	}
	if (array_size(*n_paths) == 1)
	{
		path = *(t_array **)array_get(*n_paths, 0);
		set_vertices_dist(path, 0);
		array_remove(*n_paths, 0);
	}
	return (0);
}

static void	sort_paths(t_array **paths)
{
	t_array	*path;

	path = *(t_array **)array_get(*paths, 0);
	array_remove(*paths, 0);
	array_add(paths, &path);
}

t_array	*find_n_shortest_disjoint_paths(t_array *all_simple_paths, size_t n, size_t longest_path_to_use)
{
	t_array	*n_paths;
	size_t	i;

	n_paths = array_new(n, sizeof(t_array *));
	if (n_paths == NULL)
		return (NULL);
	i = n;
	while (i < longest_path_to_use)
	{
		if (find_n_disjoint_paths(all_simple_paths, &n_paths, 0, i, n))
		{
			sort_paths(&n_paths);
			return (n_paths);
		}
		i++;
	}
	return (NULL);
}

size_t	get_longest_path_to_use(t_array *all_simple_paths, size_t max_length)
{
	size_t	i;
	t_array	*path;

	i = 0;
	while (i < array_size(all_simple_paths))
	{
		path = *(t_array **)array_get(all_simple_paths, i);
		if (array_size(path) == max_length)
			break ;
		i++;
	}
	return (i);
}

t_array	*get_shortest_path_combinations(t_graph *graph, t_array *all_simple_paths, t_array *max_flow_paths)
{
	t_array	*shortest_path_combinations;
	t_array	*n_shortest_disjoint_paths;
	size_t	max_flow_longest_path;
	size_t	longest_path_to_use;
	size_t	max_flow;
	size_t	n;

	max_flow = array_size(max_flow_paths);
	max_flow_longest_path = array_size(*(t_array **)array_get(max_flow_paths, max_flow - 1));
	longest_path_to_use = get_longest_path_to_use(all_simple_paths, max_flow_longest_path);
	shortest_path_combinations = array_new(max_flow, sizeof(t_array *));
	if (shortest_path_combinations == NULL)
		return (NULL);
	n = 1;
	while (n < max_flow && n <= 10)
	{
		set_vertices_dist(graph->vertices, 0);
		n_shortest_disjoint_paths = find_n_shortest_disjoint_paths(all_simple_paths, n, longest_path_to_use);
		if (n_shortest_disjoint_paths == NULL)
			return (NULL);
		array_add(&shortest_path_combinations, &n_shortest_disjoint_paths);
		if (PRINT_DEBUG)
			print_paths(n_shortest_disjoint_paths);
		n++;
	}
	return (shortest_path_combinations);
}
