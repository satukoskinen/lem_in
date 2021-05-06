#include <stdlib.h>
#include "lem_in.h"
#include "libft.h"

static int	parse_link(t_graph *graph, char *line)
{
	char			*ptr;
	t_graph_node	*node_1;
	t_graph_node	*node_2;
	t_edge_attr		*attr;

	ptr = ft_strchr(line, '-');
	if (ptr == NULL)
		return (-1);
	*ptr = '\0';
	node_1 = graph_find_node(graph, line);
	node_2 = graph_find_node(graph, ptr + 1);
	if (node_1 == NULL || node_2 == NULL)
		return (-1);
	attr = init_edge_attr(1);
	if (attr == NULL || !graph_add_edge(graph, node_1->key, node_2->key, attr))
		return (-1);
	attr = init_edge_attr(1);
	if (attr == NULL || !graph_add_edge(graph, node_2->key, node_1->key, attr))
		return (-1);
	*ptr = '-';
	return (1);
}

static int	validate_coordinates(char *line, t_coordinates *coordinates)
{
	coordinates->x = ft_atoi(line);
	if (coordinates->x == 0 && *line != '0')
		return (0);
	while (ft_isdigit(*line))
		line++;
	if (*line != '\0')
		line++;
	coordinates->y = ft_atoi(line);
	if (coordinates->y == 0 && *line != '0')
		return (0);
	while (ft_isdigit(*line))
		line++;
	if (*line == '\0')
		return (1);
	else
		return (0);
}

static t_node_attr	*init_node_attr(char *name, t_coordinates coordinates)
{
	t_node_attr	*attr;

	attr = (t_node_attr *)malloc(sizeof(t_node_attr));
	if (attr == NULL)
		return (NULL);
	attr->name = ft_strdup(name);
	if (attr->name == NULL)
	{
		free(attr);
		return (NULL);
	}
	attr->value = 0;
	attr->coordinates = coordinates;
	return (attr);
}

static int	parse_room(t_graph *graph, char *line, enum e_line_type *type)
{
	char			*ptr;
	t_node_attr		*attr;
	t_coordinates	coordinates;

	if (line[0] == 'L')
		return (-1);
	ptr = ft_strchr(line, ' ');
	if (ptr == NULL)
	{
		*type = LINK;
		return (parse_link(graph, line));
	}
	*ptr = '\0';
	if (!validate_coordinates(ptr + 1, &coordinates))
		return (-1);
	attr = init_node_attr(line, coordinates);
	if (attr == NULL)
		return (-1);
	if (graph_add_node(graph, attr->name, attr) == -1)
		return (-1);
	*ptr = ' ';
	if (*type == ROOM_SRC)
		((t_graph_attr *)graph->attr)->source = graph_find_node(graph, attr->name);
	else if (*type == ROOM_SINK)
		((t_graph_attr *)graph->attr)->sink = graph_find_node(graph, attr->name);
	*type = ROOM;
	return (1);
}

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

int	parse_line(t_graph *graph, t_parr *input, enum e_line_type *type)
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
