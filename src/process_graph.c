#include "lem_in.h"

t_array	find_max_flow_paths(t_graph *graph)
{
	int64_t			max_flow;
	t_graph_node	*source;
	t_graph_node	*sink;
	t_array			path_combinations;

	source = ((t_graph_attr *)graph->attr)->source;
	sink = ((t_graph_attr *)graph->attr)->sink;
	path_combinations = arr_new(1, sizeof(t_array));
	max_flow = max_flow_edmonds_karp(&path_combinations, source, sink);
	if (max_flow <= 0)
		return (CR_ARR_NULL);
	return (path_combinations);
}

int	process_graph(t_parray *output, t_graph *graph)
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
	paths = find_max_flow_paths(&transformed_graph);
	if (arr_null(&paths))
		return (-1);
	if (PRINT_DEBUG)
		arr_iter(&paths, print_path_combinations);
	ants_per_path = optimise_path_use(&paths_to_use, &paths, paths.len, ants);
	if (ants_per_path == NULL)
		return (-1);
	if (PRINT_DEBUG)
		print_ants_per_path(ants_per_path, &paths);
	return (move_ants(graph, paths_to_use, ants_per_path, output));
	if (!output)
		return (0);
	return (1);
}
