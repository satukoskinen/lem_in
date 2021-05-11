#include "lem_in.h"

int	lem_process_graph(t_parray *output, t_graph *graph)
{
	t_graph	transformed_graph;
	t_array	paths;
	t_array	*paths_to_use;
	int		ants;
	int		*ants_per_path;

	ants = ((t_node_attr *)((t_graph_attr *)graph->attr)->source->attr)->value;
	transformed_graph = lem_transform_vertex_disjoint(graph);
	if (graph_null(&transformed_graph))
		return (-1);
	paths = lem_find_max_flow_paths(&transformed_graph);
	if (arr_null(&paths))
		return (-1);
	if (PRINT_DEBUG)
		arr_iter(&paths, lem_print_path_combinations);
	ants_per_path = lem_optimise_path_use(&paths_to_use, &paths, paths.len, ants);
	if (ants_per_path == NULL)
		return (-1);
	if (PRINT_DEBUG)
		lem_print_ants_per_path(ants_per_path, &paths);
	return (lem_move_ants(graph, paths_to_use, ants_per_path, output));
	if (!output)
		return (0);
	return (1);
}
