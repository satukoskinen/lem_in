#include <stdlib.h>
#include "lem_in.h"

/*
 *	Check whether the command is "##start" or "##end" (otherwise ignore).
 *	If so, change the line type accordingly to indicate how the next line
 *	should be parsed. If the command has already been encountered or
 *	parsing rooms has already finished, return an error.
 */

static int	parse_command(t_lem *data, char *cmd, enum e_line_type *type)
{
	if (s_cmp(cmd, "##start") == 0)
	{
		if (*type != ROOM || data->s_key != NULL)
			return (-1);
		*type = ROOM_SRC;
	}
	else if (s_cmp(cmd, "##end") == 0)
	{
		if (*type != ROOM || data->t_key != NULL)
			return (-1);
		*type = ROOM_SINK;
	}
	return (1);
}

/*
 *	Parse one line of input read from stdin, depending on the current line type
 *	and whether the line contains #'s at the beginning.
 */

int	lem_parse_line(t_lem *data, t_parray *input, int fd, enum e_line_type *type)
{
	char	*line;
	int		ret;

	line = NULL;
	ret = s_readline(fd, &line);
	if (ret != 1)
		return (ret);
	if (*type == ROOM_SRC || *type == ROOM_SINK)
		ret = lem_parse_room(data, line, type);
	else if (s_ncmp(line, "##", 2) == 0)
		ret = parse_command(data, line, type);
	else if (s_ncmp(line, "#", 1) == 0)
		ret = 1;
	else if (*type == LINK)
		ret = lem_parse_link(data, line);
	else
		ret = lem_parse_room(data, line, type);
	if (ret == -1 || parr_add_last(input, line) != 1)
	{
		free(line);
		return (-1);
	}
	return (ret);
}
