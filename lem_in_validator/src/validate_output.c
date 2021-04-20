#include "lem_in_validator.h"
#include "libft.h"
#include <stdlib.h>

static int	ants_in_graph(t_graph *graph)
{
	t_vertex	*vertex;
	size_t		i;

	graph->source->value = 0;
	i = 0;
	while (i < array_size(graph->vertices))
	{
		vertex = *(t_vertex **)array_get(graph->vertices, i);
		if (vertex->value != 0)
			return (1);
		i++;
	}
	return (0);
}

int	validate_output(t_graph *graph, int ant_count)
{
	int		ret;
	int		rounds;
	char	*line;

	graph->source->value = 1;
	rounds = 0;
	ret = 1;
	while (ret == 1)
	{
		ret = get_next_line(0, &line);
		if (ret == 1)
			ret = validate_round(line, graph, ant_count);
		free(line);
		rounds++;
	}
	if (ret == -1)
		return (error("Error occurred\n", -1));
	ft_printf("Rounds: %d, nodes: %d, edges: %d\n",
		rounds, graph->vertex_count, graph->edge_count);
	if (graph->source->value != ant_count + 1)
		return (error("Not all ants were moved\n", 0));
	if (ants_in_graph(graph))
		return (error("Ants left in graph\n", 0));
	else
		return (1);
}
