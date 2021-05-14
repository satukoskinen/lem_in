#include "lem_in.h"
#include <stdlib.h>

static int	error(char *msg)
{
	print_fd(2, "%s\n", msg);
	return (1);
}

ssize_t free_string(void *str, size_t i)
{
	free(str);
	return ((ssize_t)i);
}

static void	free_resources(t_lem *data, t_parray *input, t_parray *output)
{
	lem_free_graph(&data->graph);
	if (input)
	{
		parr_iter(input, free_string);
		parr_free(input);
	}
	if (output)
	{
		parr_iter(output, free_string);
		parr_free(output);
	}
}

static ssize_t	init_resources(t_lem *data, t_parray *input, t_parray *output)
{
	*data = lem_init_data();
	if (graph_null(&data->graph))
		return (-1);
	*input = parr_new(1);
	if (parr_null(input))
	{
		lem_free_graph(&data->graph);
		return (-1);
	}
	*output = parr_new(1);
	if (parr_null(output))
	{
		lem_free_graph(&data->graph);
		parr_free(input);
		return (-1);
	}
	return (1);
}

int	main(void)
{
	t_lem		data;
	t_parray	input;
	t_parray	output;

	if (!init_resources(&data, &input, &output))
		return (error("Error"));
	if (lem_parse_input(&data, &input) != 1)
	{
		free_resources(&data, &input, &output);
		return (error("Error on parsing input"));
	}
	if (lem_process_graph(&output, &data) != 1)
	{
		free_resources(&data, &input, &output);
		return (error("Error on processing graph"));
	}
	// map_iter(&data.graph, lem_print_node);
	parr_iter(&input, lem_print_string);
	print("\n");
	parr_iter(&output, lem_print_string);
	free_resources(&data, &input, &output);
	return (0);
}
