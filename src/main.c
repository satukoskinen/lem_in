#include "lem_in.h"
#include "libft.h"

ssize_t	print_string(void *data, size_t i)
{
	ft_printf("%s\n", (char *)data);
	return ((ssize_t)i);
}

int	error(char *msg)
{
	ft_dprintf(2, "%s\n", msg);
	return (1);
}

t_graph	init_graph(void)
{
	t_graph 		graph;
	t_graph_attr	*attr;

	attr = (t_graph_attr *)malloc(sizeof(t_graph_attr));
	if (attr == NULL)
		return (CR_GRAPH_NULL);
	attr->sink = NULL;
	attr->source = NULL;
	graph = graph_new(attr);
	return (graph);
}

int main(void)
{
	t_graph	graph;
	t_parr	input;
//	t_parr	output;
//	t_array	bfs;
	t_graph	transformed_graph;

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
//	map_iter(&graph.data, print_node);
//	bfs = graph_find_shortest_path(&graph, ((t_graph_attr *)graph.attr)->source->key, ((t_graph_attr *)graph.attr)->sink->key);
//	arr_iter(&bfs, print_node);
	transformed_graph = copy_vertex_disjoint(&graph);
	map_iter(&transformed_graph.data, print_node);
	return (0);
}
