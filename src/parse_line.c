#include <stdlib.h>
#include "lem_in.h"
#include "libft.h"

t_graph_node	*graph_find_node_by_name(t_graph *graph, char *name)
{
	t_graph_node	*node;
	size_t			i;

	i = 0;
	while (i < graph->nodes.len)
	{
		node = arr_get(&graph->nodes, i);
		if (ft_strcmp(((t_node_attr *)node->attr)->name, name) == 0)
			return (node);
		i++;
	}
	return (NULL);
}

static t_edge_attr *init_edge_attr(int capacity)
{
	t_edge_attr	*attr;

	attr = (t_edge_attr *)malloc(sizeof(t_edge_attr));
	if (attr == NULL)
		return (NULL);
	attr->flow = 0;
	attr->capacity = capacity;
	return (attr);
}

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
	node_1 = graph_find_node_by_name(graph, line);
	node_2 = graph_find_node_by_name(graph, ptr + 1);
	if (node_1 == NULL || node_2 == NULL)
		return (-1);
	attr = init_edge_attr(1);
	if (attr == NULL || !graph_add_edge(graph, node_1->id, node_2->id, attr))
		return (-1);
	attr = init_edge_attr(1);	
	if (attr == NULL || !graph_add_edge(graph, node_2->id, node_1->id, attr))
		return (-1);
	*ptr = '-';
	return (1);
}

static int	init_node(t_graph_node *node, enum e_line_type *type, ssize_t id, char *name)
{
	t_node_attr	*attr;

	if (*type == ROOM_SRC)
		node->id = SOURCE;
	else if (*type == ROOM_SINK)
		node->id = SINK;
	else
		node->id = id;
	attr = (t_node_attr *)malloc(sizeof(t_node_attr));
	if (attr == NULL)
		return (0);
	attr->name = ft_strdup(name);
	if (attr->name == NULL)
	{
		free(attr);
		return (0);
	}
	attr->value = 0;
	node->attr = attr;
	return (1);
}

static int	validate_coordinates(char *line)
{
	int	value;

	value = ft_atoi(line);
	if (value == 0 && *line != '0')
		return (0);
	while (ft_isdigit(*line))
		line++;
	if (*line != '\0')
		line++;
	value = ft_atoi(line);
	if (value == 0 && *line != '0')
		return (0);
	while (ft_isdigit(*line))
		line++;
	if (*line == '\0')
		return (1);
	else
		return (0);
}

static int	parse_room(t_graph *graph, char *line, enum e_line_type *type)
{
	char			*ptr;
	t_graph_node	node;

	if (line[0] == 'L')
		return (-1);
	ptr = ft_strchr(line, ' ');
	if (ptr == NULL)
	{
		*type = LINK;
		return (parse_link(graph, line));
	}
	*ptr = '\0';
	if (!init_node(&node, type, (ssize_t)graph->nodes.len, line))
		return (-1);
	*type = ROOM;
	if (graph_add_node(graph, node) == -1)
		return (-1);
	*ptr = ' ';
	if (validate_coordinates(ptr + 1))
		return (1);
	else
		return (-1);
}

static int	parse_command(t_graph *graph, char *cmd, enum e_line_type *type)
{
	if (ft_strcmp(cmd, "##start") == 0)
	{
		if (*type != ROOM || graph_find_node(graph, SOURCE) != NULL)
			return (-1);
		*type = ROOM_SRC;
	}
	else if (ft_strcmp(cmd, "##end") == 0)
	{
		if (*type != ROOM || graph_find_node(graph, SINK) != NULL)
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
