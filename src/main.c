#include "lem_in.h"
#include <stdlib.h>

static int	error(char *msg)
{
	print_fd(2, "%s\n", msg);
	return (1);
}

int	main(void)
{
	t_graph		graph;
	t_parray	input;
	t_parray	output;

	graph = lem_init_graph();
	if (graph_null(&graph))
		return (error("Error"));
	input = parr_new(1);
	if (input.data == NULL)
		return (error("Error"));
	if (lem_parse_input(&graph, &input) != 1)
		return (error("Error on parsing input"));
	output = parr_new(1);
	if (parr_null(&output))
		return (error("Error"));
	if (lem_process_graph(&output, &graph) != 1)
		return (error("Error on processing graph"));
	parr_iter(&input, lem_print_string);
	print("\n");
	parr_iter(&output, lem_print_string);
	return (0);
}
