#include "lem_in.h"

int	lem_process_graph(t_parray *output, t_lem *data)
{
	t_lem	transformed_data;
	t_array	path_combinations;
	t_array	*paths_to_use;
	int		*ants_per_path;

	transformed_data = lem_transform_vertex_disjoint(data);
	if (graph_null(&transformed_data.graph))
		return (-1);
	path_combinations = lem_find_max_flow_paths(&transformed_data);
	lem_free_graph(&transformed_data.graph);
	if (arr_null(&path_combinations))
		return (-1);
	if (PRINT_DEBUG)
		arr_iter(&path_combinations, lem_print_path_combinations);
	ants_per_path = lem_optimise_path_use(&paths_to_use,
			&path_combinations, data->ant_count);
	if (PRINT_DEBUG)
		lem_print_ants_per_path(ants_per_path, &path_combinations);
	lem_move_ants(data, paths_to_use, ants_per_path, output);
	free(ants_per_path);
	lem_free_path_combinations(&path_combinations);
	return (1);
}
