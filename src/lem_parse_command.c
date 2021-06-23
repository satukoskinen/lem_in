#include <stdlib.h>
#include "lem_in.h"

/*
 *	Check whether the command is "##start" or "##end" (otherwise ignore).
 *	If so, change the line type accordingly to indicate how the next line
 *	should be parsed. If the command has already been encountered or
 *	parsing rooms has already finished, return an error.
 */

int	parse_command(t_lem *data, char *cmd, enum e_line_type *type)
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
