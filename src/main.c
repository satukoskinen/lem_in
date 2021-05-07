#include "lem_in.h"
#include "libft.h"

ssize_t	print_string(void *data, size_t i)
{
	ft_printf("%s\n", (char *)data);
	return ((ssize_t)i);
}

ssize_t	print_path(void *data, size_t i)
{
	ft_printf("Path %d:\n", (int)i);
	parr_iter((t_parray *)data, print_node);
	return ((ssize_t)i);
}

ssize_t	print_path_combinations(void *data, size_t i)
{
	t_array	*path;

	path = data;
	ft_printf("Iteration %d: %d paths found\n", (int)i, path->len);
	arr_iter(path, print_path);
	return ((ssize_t)i);
}

int	error(char *msg)
{
	ft_dprintf(2, "%s\n", msg);
	return (1);
}

int	process_graph(t_graph *graph)
{
	t_graph transformed_graph;
	t_array	paths;
	int		ant_count;
	int		paths_to_use;
	int		*ants_per_path;

	ant_count = ((t_node_attr *)((t_graph_attr *)graph->attr)->source)->value;
	transformed_graph = lem_transform_vertex_disjoint(&graph);
	paths = find_max_flow_paths(&transformed_graph);
	arr_iter(&paths, print_path_combinations);
	paths_to_use = (int)optimise_path_use(paths, &ants_per_path, ant_count);
}

int main(void)
{
	t_graph		graph;
	t_parray	input;
//	t_parr		output;

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
	parr_iter(&input, print_string);
	ft_printf("\n");

//	map_iter(&transformed_graph.data, print_node);

	return (0);
}
