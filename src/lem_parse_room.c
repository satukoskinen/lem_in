#include "lem_in.h"

/*
 *	Check that the room's coordinates are valid
 *	non-negative integers separated by one space
 *	and save them to coordinates.
 */

static int	validate_coordinates(char *line, t_coordinates *coordinates)
{
	coordinates->x = a_to_i(line);
	if (coordinates->x == 0 && *line != '0')
		return (0);
	while (is_digit(*line))
		line++;
	if (*line != ' ')
		return (0);
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

/*
 *	If the currently parsed line type is either ROOM_SRC or ROOM_SINK,
 *	save the room key in the data struct.
 */

static void	update_lem_data(t_lem *data, char *key, enum e_line_type type)
{
	if (type == ROOM_SRC)
		data->s_key = key;
	else
		data->t_key = key;
}

/*
 *	Validate and save a room as a node in the graph. If no spaces are found
 *	(which there should be between room name and coordinates), assume that
 *	all rooms have been parsed and switch to parsing links.
 */

int	lem_parse_room(t_lem *data, char *line, enum e_line_type *type)
{
	char			*ptr;
	t_node_attr		*attr;
	t_coordinates	coordinates;

	if (line[0] == 'L' || line[0] == '#')
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
	if (!attr || graph_add_node(&data->graph, attr->name, attr) != 1)
	{
		free(attr->name);
		free(attr);
		return (-1);
	}
	*ptr = ' ';
	if (*type == ROOM_SRC || *type == ROOM_SINK)
		update_lem_data(data, attr->name, *type);
	*type = ROOM;
	return (1);
}
