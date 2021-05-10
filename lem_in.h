#ifndef LEM_IN_H
# define LEM_IN_H

#include "core/inc/core.h"

# define PRINT_DEBUG 0

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

size_t	g_node_id;

t_graph		init_graph(void);
t_edge_attr	*init_edge_attr(int capacity);
t_node_attr	*init_node_attr(char *name, t_coordinates coordinates, t_graph_node *org);

int			parse_input(t_graph *graph, t_parray *input);
int			parse_line(t_graph *graph, t_parray *input, enum e_line_type *typ);
int			parse_link(t_graph *graph, char *line);
int			parse_room(t_graph *graph, char *line, enum e_line_type *type);

int			a_to_i(const char *str);
int			is_digit(int c);

t_graph		lem_transform_vertex_disjoint(t_graph *src);

t_array		find_max_flow_paths(t_graph *graph);
t_array		save_max_flow_paths(t_graph_node *s, t_graph_node *t, size_t max_flow);

int			map_contains_key(t_map *map, const char *key);
t_graph_edge	*get_edge(t_graph_node *src, t_graph_node *dst);

int			*optimise_path_use_simple(size_t max_flow, int ant_count);
int			*optimise_path_use(t_array **paths_to_use, t_array *path_combinations, size_t max_flow, int ant_count);
int			move_ants(t_graph *graph, t_array *paths, int *ants_per_path,
t_parray *output);

ssize_t 	print_node(void *data, size_t i);
ssize_t 	print_edge(void *data, size_t i);
ssize_t		print_string(void *data, size_t i);
ssize_t		print_path(void *data, size_t i);
ssize_t		print_path_combinations(void *data, size_t i);

#endif
