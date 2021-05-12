#include "lem_in.h"
#include <stdlib.h>

ssize_t free_string(void *str, size_t i)
{
	free(str);
	return ((ssize_t)i);
}

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
	lem_free_graph(&graph);
	parr_iter(&input, lem_print_string);
	print("\n");
	parr_iter(&output, lem_print_string);
	parr_iter(&input, free_string);
	parr_free(&input);
	parr_iter(&output, free_string);
	parr_free(&output);
	system("leaks lem_in");
	return (0);
}
