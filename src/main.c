#include "lem_in.h"
#include "libft.h"
#include <stdlib.h>

void	print_ants_per_path(int *ants_per_path, t_array *paths)
{
	size_t	i;
	t_array	*max_flow_paths;

	max_flow_paths = arr_get_last(paths);
	i = 0;
	while (i < max_flow_paths->len)
	{
		ft_printf("path %d: %d ants\n", (int)i, ants_per_path[i]);
		i++;
	}
}

int	error(char *msg)
{
	ft_dprintf(2, "%s\n", msg);
	return (1);
}

int	process_graph(t_parray *output, t_graph *graph)
{
	t_graph transformed_graph;
	t_array	paths;
	t_array	*paths_to_use;
	int		ant_count;
	int		*ants_per_path;

	ant_count = ((t_node_attr *)((t_graph_attr *)graph->attr)->source->attr)->value;
	transformed_graph = lem_transform_vertex_disjoint(graph);
	if (graph_null(&transformed_graph))
		return (-1);
	paths = find_max_flow_paths(&transformed_graph);
	if (arr_null(&paths))
		return (-1);
	arr_iter(&paths, print_path_combinations);
	printf("\n\n");
	ants_per_path = optimise_path_use(&paths_to_use, &paths, paths.len, ant_count);
	if (ants_per_path == NULL)
		return (-1);
	print_ants_per_path(ants_per_path, &paths);
	return (move_ants(graph, paths_to_use, ants_per_path, output));
	if (!output)
		return (0);
	return (1);
}

int main(void)
{
	t_graph		graph;
	t_parray	input;
	t_parray	output;

	g_node_id = 0;
	graph = init_graph();
	if (graph_null(&graph))
		return (error("Error"));
	input = parr_new(1);
	if (input.data == NULL)
	{
		return (error("Error"));
	}
	if (parse_input(&graph, &input) != 1)
	{
		return (error("Error on parsing input"));
	}
	output = parr_new(1);
	if (parr_null(&output))
	{
		return (error("Error"));
	}
	if (process_graph(&output, &graph) != 1)
	{
		return (error("Error on processing graph"));
	}
	parr_iter(&input, print_string);
	ft_printf("\n");
	parr_iter(&output, print_string);
	return (0);
}
