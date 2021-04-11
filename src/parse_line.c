#include <stdlib.h>
#include "lem_in.h"
#include "graph.h"
#include "libft.h"

static int	parse_link(t_graph *graph, char *line)
{
	char	*ptr;
	int		ret;

	ptr = ft_strchr(line, '-');
	if (ptr == NULL)
		return (-1);
	*ptr = '\0';
	ret = graph_add_edge(graph, line, ptr + 1);
	if (ret != 1)
		return (-1);
	ret = graph_add_edge(graph, ptr + 1, line);
	*ptr = '-';
	if (ret != 1)
		return (-1);
	else
		return (ret);
}

static int	parse_special_room(t_graph *graph, enum e_line_type *type)
{
	t_vertex	*vertex;

	vertex = (t_vertex *)array_get(graph->vertices,
			array_size(graph->vertices) - 1);
	if (*type == ROOM_SRC)
	{
		vertex->is_source = 1;
		graph->has_source = 1;
	}
	else
	{
		vertex->is_sink = 1;
		graph->has_sink = 1;
	}
	*type = ROOM;
	return (1);
}

static int	parse_room(t_graph *graph, char *line, enum e_line_type *type)
{
	char	*ptr;
	int		ret;

	if (line[0] == 'L')
		return (-1);
	ptr = ft_strchr(line, ' ');
	if (ptr == NULL)
	{
		*type = LINK;
		ret = parse_link(graph, line);
		return (ret);
	}
	*ptr = '\0';
	ret = graph_add_vertex(graph, line, 0);
	if (ret == 1 && (*type == ROOM_SRC || *type == ROOM_SINK))
		parse_special_room(graph, type);
	*ptr = ' ';
	ptr = ft_strchr(ptr + 1, ' ');
	if (ptr == NULL)
		return (-1);
	ptr = ft_strchr(ptr + 1, ' ');
	if (ptr == NULL)
		return (ret);
	else
		return (-1);
}

static int	parse_command(t_graph *graph, char *cmd, enum e_line_type *type)
{
	if (ft_strcmp(cmd, "##start") == 0)
	{
		if (*type != ROOM || graph->has_source)
			return (-1);
		*type = ROOM_SRC;
	}
	else if (ft_strcmp(cmd, "##end") == 0)
	{
		if (*type != ROOM || graph->has_sink)
			return (-1);
		*type = ROOM_SINK;
	}
	return (1);
}

int	parse_line(t_graph *graph, t_array **input, enum e_line_type *type)
{
	char	*line;
	int		ret;

	line = NULL;
	ret = get_next_line(0, &line);
	if (ret != 1)
		return (ret);
	if (*type == ROOM_SRC || *type == ROOM_SINK)
		ret = parse_room(graph, line, type);
	else if (strncmp(line, "##", 2) == 0)
		ret = parse_command(graph, line, type);
	else if (strncmp(line, "#", 1) == 0)
		ret = 1;
	else if (*type == LINK)
		ret = parse_link(graph, line);
	else
		ret = parse_room(graph, line, type);
	if (ret == -1 || array_add(input, &line) == NULL)
	{
		free(line);
		return (-1);
	}
	return (ret);
}
