#ifndef LEM_IN_H
# define LEM_IN_H

# include "graph.h"

# define PRINT_DEBUG 1

enum e_line_type
{
	ROOM,
	ROOM_SRC,
	ROOM_SINK,
	LINK
};

int		parse_input(t_graph *graph, t_array **input);
int		parse_line(t_graph *graph, t_array **input, enum e_line_type *type);
int		process_graph(t_graph *graph, t_array **output);
int		find_shortest_path(t_graph *graph, t_vertex *src, t_vertex *dst);
int		max_flow_edmonds_karp(t_graph *graph, t_vertex *src, t_vertex *dst);
t_array	*save_paths(t_graph *graph, t_vertex *src, t_vertex *sink, int count);
int		move_ants(t_graph *graph, t_array *shortest_path,
			t_array *max_flow_paths, t_array **output);

#endif