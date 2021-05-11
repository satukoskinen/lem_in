#include <stdlib.h>
#include "lem_in.h"

static int	parse_command(t_graph *graph, char *cmd, enum e_line_type *type)
{
	if (s_cmp(cmd, "##start") == 0)
	{
		if (*type != ROOM || ((t_graph_attr *)graph->attr)->source != NULL)
			return (-1);
		*type = ROOM_SRC;
	}
	else if (s_cmp(cmd, "##end") == 0)
	{
		if (*type != ROOM || ((t_graph_attr *)graph->attr)->sink != NULL)
			return (-1);
		*type = ROOM_SINK;
	}
	return (1);
}

int	lem_parse_line(
	t_graph *graph,
	t_parray *input,
	enum e_line_type *type)
{
	char	*line;
	int		ret;

	line = NULL;
	ret = s_readline(0, &line);
	if (ret != 1)
		return (ret);
	if (*type == ROOM_SRC || *type == ROOM_SINK)
		ret = lem_parse_room(graph, line, type);
	else if (s_ncmp(line, "##", 2) == 0)
		ret = parse_command(graph, line, type);
	else if (s_ncmp(line, "#", 1) == 0)
		ret = 1;
	else if (*type == LINK)
		ret = lem_parse_link(graph, line);
	else
		ret = lem_parse_room(graph, line, type);
	if (ret == -1 || !parr_add_last(input, line))
	{
		free(line);
		return (-1);
	}
	return (ret);
}
