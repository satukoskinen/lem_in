#ifndef LEM_IN_VALIDATOR_H
# define LEM_IN_VALIDATOR_H

# include "graph.h"

enum e_line_type
{
	ROOM,
	ROOM_SRC,
	ROOM_SINK,
	LINK
};

int		parse_input(t_graph *graph);
int		parse_line(t_graph *graph, enum e_line_type *type);
int		validate_output(t_graph *graph, int ant_count);
int		validate_round(char *line, t_graph *graph, int ants);
int		error(char *msg, int return_value);

#endif