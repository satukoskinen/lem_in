#include "lem_in.h"

static int	validate_coordinates(char *line, t_coordinates *coordinates)
{
	coordinates->x = a_to_i(line);
	if (coordinates->x == 0 && *line != '0')
		return (0);
	while (is_digit(*line))
		line++;
	if (*line != '\0')
		line++;
	coordinates->y = a_to_i(line);
	if (coordinates->y == 0 && *line != '0')
		return (0);
	while (is_digit(*line))
		line++;
	if (*line == '\0')
		return (1);
	else
		return (0);
}

int	lem_parse_room(t_lem *data, char *line, enum e_line_type *type)
{
	char			*ptr;
	t_node_attr		*attr;
	t_coordinates	coordinates;

	if (line[0] == 'L')
		return (-1);
	ptr = s_chr(line, ' ');
	if (ptr == NULL)
	{
		*type = LINK;
		return (lem_parse_link(data, line));
	}
	*ptr = '\0';
	if (!validate_coordinates(ptr + 1, &coordinates))
		return (-1);
	attr = lem_init_node_attr(line, coordinates, NULL);
	if (attr == NULL)
		return (-1);
	if (graph_add_node(&data->graph, attr->name, attr) == -1)
		return (-1);
	*ptr = ' ';
	if (*type == ROOM_SRC)
		data->s_key = attr->name;
	else if (*type == ROOM_SINK)
		data->t_key = attr->name;
	*type = ROOM;
	return (1);
}
