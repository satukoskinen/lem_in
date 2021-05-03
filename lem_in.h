#ifndef LEM_IN_H
# define LEM_IN_H

#include "../core/inc/core.h"
#include "../core/graph/inc/graph.h"

# define SOURCE -1
# define SINK -2

enum e_line_type
{
	ROOM,
	ROOM_SRC,
	ROOM_SINK,
	LINK
};

typedef struct	s_node_attr
{
	char		*name;
	int			value;
}				t_node_attr;

typedef struct	s_edge_attr
{
	ssize_t		flow;
	ssize_t		capacity;
}				t_edge_attr;

int	parse_input(t_graph *graph, t_parr *input);
int	parse_line(t_graph *graph, t_parr *input, enum e_line_type *type);

#endif
