#ifndef LEM_IN_H
# define LEM_IN_H

# include "core/inc/core.h"
# include <pthread.h>
# include <unistd.h>

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
	t_ssize			flow;
	t_ssize			capacity;
	t_graph_edge	*reverse_edge;
}					t_edge_attr;

typedef struct s_graph_attr
{
	t_graph_node	*source;
	t_graph_node	*sink;
}					t_graph_attr;

typedef struct s_flag
{
	char	*name_long;
	char	*name_short;
	t_bool	argument_required;
}			t_flag;

typedef struct s_flags
{
	t_bool	usage;
	t_bool	verbose;
	t_bool	read_from_file;
	char	*file;
}			t_flags;

typedef struct s_lem
{
	t_graph		graph;
	const char	*s_key;
	const char	*t_key;
	t_size		ant_count;
}				t_lem;

typedef t_array	t_paths;

void			lem_exit_error(char *msg);

t_lem			lem_init_data(void);
t_edge_attr		*lem_init_edge_attr(int capacity);
t_node_attr		*lem_init_node_attr(char *name,
					t_coordinates coordinates, t_graph_node *org);

int				lem_parse_flags(t_flags *flags, int argc, char **argv);
int				lem_parse_input(t_lem *data, t_parray *input, t_flags flags);
int				lem_parse_line(t_lem *data, t_parray *input, int fd,
					enum e_line_type *type);
int				lem_parse_link(t_lem *data, char *line);
int				lem_parse_room(t_lem *data, char *line, enum e_line_type *type);

int				a_to_i(const char *str);

int				lem_process_graph(t_parray *output, t_lem *data, t_flags flags);
t_lem			lem_transform_vertex_disjoint(t_lem *data);
t_parray		lem_find_max_flow_paths(t_lem *lem);
t_parray		*lem_save_max_flow_paths(t_graph_node *s, t_graph_node *t,
					t_size max_flow);

t_graph_edge	*lem_get_edge(t_graph_node *src, t_graph_node *dst);
t_ssize			lem_compare_nodes(t_graph_node *n1, t_graph_node *n2);
t_ssize			lem_edge_remaining_capacity(t_graph_edge *edge);
void			lem_free_graph(t_graph *graph);
void			lem_free_path_combinations(t_parray *path_combinations);

void			lem_optimise_path_use(int *ants_per_path, t_parray **paths_to_use,
					t_parray *path_combinations, t_size ants);
void			lem_move_ants(t_lem *data, t_parray *paths,
					int *ants_per_path, t_parray *output);

int				lem_print_usage(void);
void			lem_print_result(t_parray *input, t_parray *output);
t_ssize			lem_print_node(void *data, t_size i);
t_ssize			lem_print_edge(void *data, t_size i);
t_ssize			lem_print_string(void *data, t_size i);
t_ssize			lem_print_path(void *data, t_size i);
t_ssize			lem_print_path_combinations(void *data, t_size i);
void			lem_print_ants_per_path(int *ants_per_path, t_parray *paths);
void			lem_print_result(t_parray *input, t_parray *output);

#endif
