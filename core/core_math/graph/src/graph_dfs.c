/**
 *
 * \authors Julius Koskela
 *
 * \brief Depth first search on a directed graph.
 *
 * Performs a depth first search on a graph saving the result as edges
 * put into an array. If NULL is passed as destination, will search the
 * whole graph. Checks of edges are valid as well and won't traverse edges
 * that are marked as invalid. This is helpful with max flow for example.
 *
 * \param g Source graph.
 * \param s_key Source node key.
 * \param t_key Sink node key.
 *
 * \return A list of edges.
 *
 */

#include "../../../inc/core.h"

static void	graph_dfs_loop(
	t_edges *res,
	t_graph_node *v,
	t_graph_node *t)
{
	t_graph_edge	*e;
	t_size			i;

	v->valid = 0;
	i = FALSE;
	while (i < v->out.len)
	{
		e = parr_get(&v->out, i);
		if (e->valid && e->v->valid)
		{
			parr_add_last(res, e);
			graph_dfs_loop(res, e->v, t);
		}
		if (t && s_cmp(v->key, t->key) == 0)
			return ;
		i++;
	}
	return ;
}

t_edges	graph_dfs(t_graph *g, const char *s_key, const char *t_key)
{
	t_nodes			queue;
	t_edges			res;
	t_graph_node	*s;
	t_graph_node	*t;

	s = graph_find_node(g, s_key);
	t = graph_find_node(g, t_key);
	if (!s)
		return ((t_parray){NULL, 0, 0});
	res = parr_new(1);
	queue = parr_new(1);
	parr_add_last(&queue, s);
	graph_dfs_loop(&res, s, t);
	parr_free(&queue);
	map_iter(g, graph_node_valid);
	return (res);
}
