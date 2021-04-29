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

t_array	*get_shortest_paths(t_graph *graph);

t_array	*get_max_flow_paths(t_graph *graph);

int		find_shortest_path(t_graph *graph, t_vertex *src, t_vertex *dst);

int		max_flow_edmonds_karp(t_graph *graph, t_vertex *src, t_vertex *dst, t_array **path_combinations);

int		*optimize_path_use(int ant_count, t_array *paths, t_array **paths_to_use);

int		move_ants(t_graph *graph, t_array *paths, int *ants_per_path,
			t_array **output);

t_array	*insert_path_to_array(t_array **paths, t_array **path);

t_array	*find_all_simple_paths(t_graph *graph, t_vertex *src, t_vertex *dst);

t_array	*get_shortest_path_combinations(t_graph *graph, t_array *all_simple_paths, t_array *max_flow_paths);

void	print_paths(t_array *paths);

t_array	*save_flow_paths(t_graph *graph, t_vertex *src,
t_vertex *sink, size_t count);

#endif
