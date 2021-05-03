#include <stdlib.h>
#include "lem_in.h"
#include "libft.h"

static int	parse_ant_count(t_array **input)
{
	char	*line;
	int		ret;
	int		ant_count;

	line = NULL;
	ret = get_next_line(0, &line);
	if (ret != 1)
		return (-1);
	ant_count = ft_atoi(line);
	if (ant_count == 0 && line[0] != '0')
		ant_count = -1;
	if (array_add(input, &line) == NULL)
	{
		free(line);
		return (-1);
	}
	return (ant_count);
}

/*
** parse input
*/

int	parse_input(t_graph *graph, t_array **input)
{
	int					ant_count;
	int					ret;
	enum e_line_type	type;

	ant_count = parse_ant_count(input);
	if (ant_count == -1)
		return (-1);
	type = ROOM;
	ret = 1;
	while (ret == 1)
		ret = parse_line(graph, input, &type);
	if (ret == -1)
		return (-1);
	if (graph->vertex_count == 0 || graph->edge_count == 0)
		return (-1);
	else if (graph->source_index == -1 || graph->sink_index == -1)
		return (-1);
	graph->source = *(t_vertex **)array_get(graph->vertices,
			(size_t)graph->source_index);
	graph->sink = *(t_vertex **)array_get(graph->vertices, (size_t)graph->sink_index);
	graph->source->value = ant_count;
	return (1);
}
