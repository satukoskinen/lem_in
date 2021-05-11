#include "lem_in.h"

static int	parse_ant_count(t_parray *input)
{
	char	*line;
	int		ret;
	int		ant_count;

	line = NULL;
	ret = s_readline(0, &line);
	if (ret != 1)
		return (-1);
	ant_count = a_to_i(line);
	if (ant_count == 0 && line[0] != '0')
	{
		free(line);
		return (-1);
	}
	if (!parr_add_last(input, line))
	{
		free(line);
		return (-1);
	}
	return (ant_count);
}

int	lem_parse_input(t_graph *graph, t_parray *input)
{
	int					ant_count;
	int					ret;
	enum e_line_type	type;
	t_graph_node		*src;
	size_t				line_nbr;

	line_nbr = 0;
	ant_count = parse_ant_count(input);
	if (ant_count == -1)
		return (-1);
	type = ROOM;
	ret = 1;
	while (ret == 1)
	{
		ret = lem_parse_line(graph, input, &type);
		line_nbr++;
	}
	if (ret == -1)
		return (-1);
	if (((t_graph_attr *)graph->attr)->sink == NULL
		|| ((t_graph_attr *)graph->attr)->source == NULL)
		return (-1);
	src = ((t_graph_attr *)graph->attr)->source;
	((t_node_attr *)src->attr)->value = ant_count;
	return (1);
}
