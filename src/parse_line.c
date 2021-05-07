#include <stdlib.h>
#include "lem_in.h"
#include "libft.h"

static int	parse_command(t_graph *graph, char *cmd, enum e_line_type *type)
{
	if (ft_strcmp(cmd, "##start") == 0)
	{
		if (*type != ROOM || ((t_graph_attr *)graph->attr)->source != NULL)
			return (-1);
		*type = ROOM_SRC;
	}
	else if (ft_strcmp(cmd, "##end") == 0)
	{
		if (*type != ROOM || ((t_graph_attr *)graph->attr)->sink != NULL)
			return (-1);
		*type = ROOM_SINK;
	}
	return (1);
}

int	parse_line(t_graph *graph, t_parray *input, enum e_line_type *type)
{
	char	*line;
	int		ret;

	line = NULL;
	ret = get_next_line(0, &line);
	if (ret != 1)
		return (ret);
	if (*type == ROOM_SRC || *type == ROOM_SINK)
		ret = parse_room(graph, line, type);
	else if (ft_strncmp(line, "##", 2) == 0)
		ret = parse_command(graph, line, type);
	else if (ft_strncmp(line, "#", 1) == 0)
		ret = 1;
	else if (*type == LINK)
		ret = parse_link(graph, line);
	else
		ret = parse_room(graph, line, type);
	if (ret == -1 || !parr_add_last(input, line))
	{
		free(line);
		return (-1);
	}
	return (ret);
}
