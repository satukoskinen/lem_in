/*
** Graph.h
*/

#ifndef GRAPH_H
# define GRAPH_H

# include "array.h"

# define INIT_SIZE 5

typedef struct s_vertex
{
	char			*id;
	int				value;
	int				dist;
	int				is_source;
	int				is_sink;
	t_array			*adj_list;
	struct s_vertex	*prev;
}					t_vertex;

typedef struct s_graph
{
	t_array		*vertices;
	t_vertex	*source;
	t_vertex	*sink;
	int			source_index;
	int			sink_index;
	int			vertex_count;
	int			edge_count;
}				t_graph;

typedef struct s_edge
{
	t_vertex	*src;
	t_vertex	*dst;
	int			value;
}				t_edge;

t_graph	*graph_new(void);
int		graph_add_vertex(t_graph *graph, char *id, int value);
int		graph_add_edge(t_graph *graph, char *v1_id, char *v2_id);
int		graph_contains_vertex(t_graph *graph, char *v_id);
int		graph_contains_edge(t_graph *graph, char *v1_id, char *v2_id);
void	graph_print_vertices(t_graph *graph);
void	graph_print_edges(t_graph *graph);
void	graph_del(t_graph **graph);

#endif
