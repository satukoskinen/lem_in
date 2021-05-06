#include "lem_in.h"
#include "libft.h"

static int	parse_ant_count(t_parr *input)
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

int	parse_input(t_graph *graph, t_parr *input)
{
	int					ant_count;
	int					ret;
	enum e_line_type	type;
	t_graph_node		*src;

	ant_count = parse_ant_count(input);
	if (ant_count == -1)
		return (-1);
	type = ROOM;
	ret = 1;
	while (ret == 1)
		ret = parse_line(graph, input, &type);
	if (ret == -1)
		return (-1);
	if (((t_graph_attr *)graph->attr)->sink == NULL
		|| ((t_graph_attr *)graph->attr)->source == NULL)
		return (-1);
	src = ((t_graph_attr *)graph->attr)->source;
	((t_node_attr *)src->attr)->value = ant_count;
	return (1);
}
