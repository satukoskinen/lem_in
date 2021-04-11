#ifndef LEM_IN_H
# define LEM_IN_H

# include "graph.h"

enum e_line_type
{
	ROOM,
	ROOM_SRC,
	ROOM_SINK,
	LINK
};

int	parse_input(t_graph *graph, t_array **input);
int	parse_line(t_graph *graph, t_array **input, enum e_line_type *type);

#endif