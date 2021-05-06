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

typedef struct s_coordinates
{
	int			x;
	int			y;
}				t_coordinates;

typedef struct s_node_attr
{
	char			*name;
	int				value;
	t_coordinates	coordinates;
	t_graph_node	*org;
}					t_node_attr;

typedef struct s_edge_attr
{
	ssize_t			flow;
	ssize_t			capacity;
	t_graph_edge	*reverse_edge;
}					t_edge_attr;

typedef struct s_graph_attr
{
	t_graph_node	*source;
	t_graph_node	*sink;
}					t_graph_attr;

int	parse_input(t_graph *graph, t_parr *input);
int	parse_line(t_graph *graph, t_parr *input, enum e_line_type *type);
t_graph	copy_vertex_disjoint(t_graph *src);

t_edge_attr *init_edge_attr(int capacity);
t_node_attr	*init_node_attr(char *name, t_coordinates coordinates, t_graph_node *org);

ssize_t print_node(void *data, size_t i);
ssize_t print_edge(void *data, size_t i);

#endif
