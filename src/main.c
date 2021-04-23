#include "lem_in.h"
#include "libft.h"
#include <stdlib.h>
#include <time.h>

static int	error(char *msg)
{
	ft_putstr_fd(msg, 2);
	return (1);
}

static void	print_array(t_array *input)
{
	char	*line;
	size_t	i;

	i = 0;
	while (i < array_size(input))
	{
		line = *(char **)array_get(input, i);
		ft_printf("%s\n", line);
		i++;
	}
}

static void	free_resources(t_graph **graph, t_array **input, t_array **output)
{
	size_t	i;

	i = 0;
	while (i < array_size(*input))
	{
		free(*(char **)array_get(*input, i));
		i++;
	}
	array_del(input);
	i = 0;
	while (i < array_size(*output))
	{
		free(*(char **)array_get(*output, i));
		i++;
	}
	array_del(output);
	graph_del(graph);
}

static int	init_resources(t_graph **graph, t_array **input, t_array **output)
{
	*graph = graph_new();
	if (*graph == NULL)
		return (0);
	*input = array_new(INIT_SIZE, sizeof(char *));
	if (*input == NULL)
	{
		graph_del(graph);
		return (0);
	}
	*output = array_new(INIT_SIZE, sizeof(char *));
	if (*output == NULL)
	{
		graph_del(graph);
		array_del(input);
		return (0);
	}
	return (1);
}

/*
** main
*/

int	main(void)
{
	t_graph	*graph;
	t_array	*input;
	t_array	*output;
	clock_t	tic, toc;

	if (init_resources(&graph, &input, &output) != 1)
		return (error("Error\n"));
//	ft_putstr("read input...\n");
	tic = clock();
	if (parse_input(graph, &input) != 1)
	{
		free_resources(&graph, &input, &output);
		return (error("Error on reading input\n"));
	}
	toc = clock();
//	ft_printf("elapsed: %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);
//	ft_putstr("process graph...\n");
	tic = clock();
	if (process_graph(graph, &output) != 1)
	{
		free_resources(&graph, &input, &output);
		return (error("Error on processing graph\n"));
	}
	toc = clock();
//	ft_printf("elapsed: %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);
//	ft_putstr("print...\n");
	print_array(input);
	ft_putstr("\n");
	print_array(output);
	free_resources(&graph, &input, &output);
	system("leaks lem_in");
	return (0);
}
