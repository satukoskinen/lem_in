/**
 *
 * \authors Julius Koskela
 *
 * \brief Breadth first search on a graph.
 *
 * Performs a breadth first search on a graph saving the result as edges
 * put into an array. If NULL is passed as destination, will search the
 * whole graph. Checks of edges are valid as well and won't traverse edges
 * that are marked as invalid. This is helpful with max flow for example.
 *
 * \param g Source graph.
 * \param src_key Key of the root of the search.
 * \param dst_key Key of the destination of the search. If NULL is passed
 * will seacrh the whole graph.
 *
 * \return An array containing a list of edges.
 *
 */

#include "../../../inc/core.h"

static t_ssize	graph_iter_edges(
	t_parray *res,
	t_nodes *queue,
	t_graph_node *t,
	t_size queue_index)
{
	t_graph_edge	*e;
	t_graph_node	*v;
	t_size			i;

	v = parr_get(queue, queue_index);
	i = 0;
	while (i < v->out.len)
	{
		e = parr_get(&v->out, i);
		if (!e)
			return (-1);
		if (e->valid && e->v->valid)
		{
			e->v->valid = FALSE;
			parr_add_last(res, e);
			parr_add_last(queue, e->v);
			v = parr_get(queue, queue_index);
			if (t && s_cmp(e->v->key, t->key) == 0)
				return (TRUE);
		}
		i++;
	}
	return (FALSE);
}

static void	graph_bfs_loop(
	t_parray *res,
	t_graph_node *s,
	t_graph_node *t)
{
	t_nodes			queue;
	t_graph_node	*v;
	t_size			i;

	queue = parr_new(1);
	s->valid = FALSE;
	parr_add_last(&queue, s);
	i = 0;
	while (i < queue.len)
	{
		v = parr_get(&queue, i);
		v->valid = FALSE;
		if (graph_iter_edges(res, &queue, t, i))
		{
			parr_free(&queue);
			return ;
		}
		i++;
	}
	parr_free(&queue);
	return ;
}

t_parray	graph_bfs(t_graph *g, const char *s_key, const char *t_key)
{
	t_parray		res;
	t_graph_node	*s;
	t_graph_node	*t;

	s = graph_find_node(g, s_key);
	t = graph_find_node(g, t_key);
	if (!s)
		return ((t_parray){NULL, 0, 0});
	res = parr_new(1);
	graph_bfs_loop(&res, s, t);
	map_iter(g, graph_node_valid);
	return (res);
}
