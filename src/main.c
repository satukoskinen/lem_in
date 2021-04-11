#include "libft.h"
#include "lem_in.h"
#include "graph.h"
#include <stdlib.h>

int	error(char *msg)
{
	ft_putstr(msg);
	return (1);
}

void	print_input(t_array *input)
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

void	free_resources(t_graph **graph, t_array **input)
{
	size_t	i;

	i = 0;
	while (i < array_size(*input))
	{
		free(*(char **)array_get(*input, i));
		i++;
	}
	array_del(input);
	graph_del(graph);
}

int	main(void)
{
	t_graph	*graph;
	t_array	*input;

	graph = graph_new();
	if (graph == NULL)
		return (error("Error\n"));
	input = array_new(INIT_SIZE, sizeof(char *));
	if (input == NULL)
	{
		graph_del(&graph);
		return (error("Error\n"));
	}
	if (parse_input(graph, &input) != 1)
	{
		free_resources(&graph, &input);
		return (error("Error on reading input\n"));
	}
	graph_print_vertices(graph);
	graph_print_edges(graph);
	print_input(input);
	free_resources(&graph, &input);
	return (0);
}

/*
//	system("leaks lem_in");
int main(void)
{
	t_graph *graph;

	graph = graph_new();
	if (graph == NULL)
		return (error("Error\n"));
	graph_add_vertex(graph, "V0", 0);
	graph_add_vertex(graph, "V1", 0);
	graph_add_edge(graph, "V0", "V1");
	graph_add_edge(graph, "V1", "V0");
	graph_add_vertex(graph, "V2", 0);
	graph_add_edge(graph, "V0", "V2");
	graph_print_vertices(graph);
	graph_print_edges(graph);
}
*/