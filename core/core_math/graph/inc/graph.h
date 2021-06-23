#ifndef GRAPH_H
# define GRAPH_H
# include "../../../core_containers/parray/inc/parr.h"
# include "../../../core_containers/map/inc/map.h"
# include "../../../core_standard/memory/inc/memory.h"
# include "../../../core_string/cstring/inc/cstr.h"
# include "../../../inc/types.h"

/**
 *
 * \authors Julius Koskela, Satu Koskinen
 *
 * \brief A graph implementation.
 *
 */

t_graph			graph_new(void);
t_ssize			graph_add_node(t_graph *g, const char *key, void *attr);
t_graph_node	*graph_find_node(t_graph *g, const char *key);
t_ssize			graph_add_edge(t_graph *g, const char *s_key,
					const char *t_key, void *attr);
t_ssize			graph_cmp_nodes(const void *n1, const void *n2);
t_nodes			graph_find_roots(t_graph *g);
t_edges			graph_bfs(t_graph *g, const char *s_key, const char *t_key);
t_edges			graph_dfs(t_graph *g, const char *s_key, const char *t_key);
t_nodes			graph_find_shortest_path(t_graph *g,
					const char *s_key, const char *t_key);
t_nodes			graph_edge_backtrack(t_parray *edges, const char *s_key,
					t_ssize (*f)(t_graph_edge *));
t_graph_edge	*graph_find_edge(t_graph *g,
					const char *s_key, const char *t_key);
t_ssize			graph_node_valid(void *data, t_size i);
t_ssize			graph_null(t_graph *g);

#endif
