#include "lem_in.h"

ssize_t free_path(void *data, size_t i)
{
	t_parray	*path;

	path = data;
	parr_free(path);
	return ((ssize_t)i);
}

ssize_t free_paths(void *data, size_t i)
{
	t_array	*paths;

	paths = data;
	arr_iter(paths, free_path);
	arr_free(paths);
	return ((ssize_t)i);
}

void	lem_free_path_combinations(t_array *path_combinations)
{
	arr_iter(path_combinations, free_paths);
	arr_free(path_combinations);
}

int	lem_process_graph(t_parray *output, t_graph *graph)
{
	t_graph	transformed_graph;
	t_array	path_combinations;
	t_array	*paths_to_use;
	int		ants;
	int		*ants_per_path;

	transformed_graph = lem_transform_vertex_disjoint(graph);
	if (graph_null(&transformed_graph))
		return (-1);
	path_combinations = lem_find_max_flow_paths(&transformed_graph);
	lem_free_graph(&transformed_graph);
	if (arr_null(&path_combinations))
		return (-1);
	if (PRINT_DEBUG)
		arr_iter(&path_combinations, lem_print_path_combinations);
	ants = ((t_node_attr *)((t_graph_attr *)graph->attr)->source->attr)->value;
	ants_per_path = lem_optimise_path_use(&paths_to_use, &path_combinations, ants);
	if (ants_per_path == NULL)
		return (-1);
	if (PRINT_DEBUG)
		lem_print_ants_per_path(ants_per_path, &path_combinations);
	lem_move_ants(graph, paths_to_use, ants_per_path, output);
	free(ants_per_path);
	lem_free_path_combinations(&path_combinations);
	if (!output)
		return (0);
	return (1);
}
