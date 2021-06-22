#include "lem_in.h"

/*
 *	Transform the graph to turn node capacities into edge capacities,
 *	find the max flow paths for the transformed graph (if there are any),
 *	choose the combination of paths to use and the amount of ants to send
 *	down each path, and finally move the ants and save the rounds to output.
 */

int	lem_process_graph(t_parray *output, t_lem *data, t_flags flags)
{
	t_lem		transformed_data;
	t_parray	path_combinations;
	t_parray	*paths_to_use;
	int			*ants_per_path;

	transformed_data = lem_transform_vertex_disjoint(data);
	path_combinations = lem_find_max_flow_paths(&transformed_data);
	lem_free_graph(&transformed_data.graph);
	if (parr_null(&path_combinations))
		return (-1);
	if (flags.verbose)
		parr_iter(&path_combinations, lem_print_path_combinations);
	ants_per_path = (int *)malloc(sizeof(int) * path_combinations.len);
	if (!ants_per_path)
		lem_exit_error("ants per path");
	lem_optimise_path_use(ants_per_path, &paths_to_use,
		&path_combinations, data->ant_count);
	if (flags.verbose)
		lem_print_ants_per_path(ants_per_path, paths_to_use);
	lem_move_ants(data, paths_to_use, ants_per_path, output);
	free(ants_per_path);
	lem_free_path_combinations(&path_combinations);
	return (1);
}
