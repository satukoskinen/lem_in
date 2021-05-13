#ifndef LEM_IN_H
# define LEM_IN_H

# include "core/inc/core.h"
# include <pthread.h>
# include <unistd.h>

# define PRINT_DEBUG 0

enum e_line_type
{
	ROOM,
	ROOM_SRC,
	ROOM_SINK,
	LINK
};

typedef struct	s_coordinates
{
	int			x;
	int			y;
}				t_coordinates;

typedef struct		s_node_attr
{
	char			*name;
	int				value;
	t_coordinates	coordinates;
	t_graph_node	*org;
}					t_node_attr;

typedef struct		s_edge_attr
{
	ssize_t			flow;
	ssize_t			capacity;
	t_graph_edge	*reverse_edge;
}					t_edge_attr;

typedef struct		s_graph_attr
{
	t_graph_node	*source;
	t_graph_node	*sink;
}					t_graph_attr;

typedef struct	s_lem
{
	t_graph		graph;
	const char	*s_key;
	const char	*t_key;
	size_t		ant_count;
}				t_lem;

typedef t_array	t_paths;

t_lem			lem_init_data(void);
t_edge_attr		*lem_init_edge_attr(int capacity);
t_node_attr		*lem_init_node_attr(char *name,
					t_coordinates coordinates, t_graph_node *org);

int				lem_parse_input(t_lem *data, t_parray *input);
int				lem_parse_line(t_lem *data, t_parray *input,
					enum e_line_type *type);
int				lem_parse_link(t_lem *data, char *line);
int				lem_parse_room(t_lem *data, char *line, enum e_line_type *type);

int				a_to_i(const char *str);

int				lem_process_graph(t_parray *output, t_lem *data);
t_lem			lem_transform_vertex_disjoint(t_lem *data);
t_array			lem_find_max_flow_paths(t_graph *graph);
t_array			lem_save_max_flow_paths(t_graph_node *s, t_graph_node *t,
					size_t max_flow);

t_graph_edge	*lem_get_edge(t_graph_node *src, t_graph_node *dst);
ssize_t			lem_compare_nodes(t_graph_node *n1, t_graph_node *n2);
ssize_t			lem_edge_remaining_capacity(t_graph_edge *edge);
ssize_t			lem_find_node(t_array *dst, t_graph_node *node);
void			lem_free_graph(t_graph *graph);
void			lem_free_path_combinations(t_array *path_combinations);

int				*lem_optimise_path_use(t_array **paths_to_use,
					t_array *path_combinations, int ants);
int				lem_move_ants(t_lem *data, t_array *paths,
					int *ants_per_path, t_parray *output);

ssize_t			lem_print_node(void *data, size_t i);
ssize_t			lem_print_edge(void *data, size_t i);
ssize_t			lem_print_string(void *data, size_t i);
ssize_t			lem_print_path(void *data, size_t i);
ssize_t			lem_print_path_combinations(void *data, size_t i);
void			lem_print_ants_per_path(int *ants_per_path, t_array *paths);

#endif
