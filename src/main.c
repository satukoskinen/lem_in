#include "lem_in.h"
#include <stdlib.h>

static ssize_t	free_string(void *str, size_t i)
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

static void	init_resources(t_lem *data, t_parray *input, t_parray *output)
{
	*data = lem_init_data();
	if (graph_null(&data->graph))
		lem_exit_error("ERROR");
	*input = parr_new(1);
	if (parr_null(input))
		lem_exit_error("ERROR");
	*output = parr_new(1);
	if (parr_null(output))
		lem_exit_error("ERROR");
}

int	main(void)
{
	t_lem		data;
	t_parray	input;
	t_parray	output;

	init_resources(&data, &input, &output);
	if (lem_parse_input(&data, &input) != 1)
	{
		free_resources(&data, &input, &output);
		lem_exit_error("Error on parsing input");
	}
	if (lem_process_graph(&output, &data) != 1)
	{
		free_resources(&data, &input, &output);
		lem_exit_error("Error on processing graph");
	}
	lem_print_result(&input, &output);
	free_resources(&data, &input, &output);
	return (0);
}
