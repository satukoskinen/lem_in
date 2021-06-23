/**
 *
 * \authors Julius Koskela
 *
 * \brief Backtrack edges and store nodes in a path.
 *
 * Traverses a list of edges from the sink node to the first node assuming that
 * the sink node is the destination node of the last edge in the list. If `f`
 * is not NULL, will execute f on each traversed edge. This can be used to
 * update edge validity or attributes. Can also stop the backtracking by
 * returning 0 from f.
 *
 * \param edges List of edges as returned from breadth first search.
 *
 * \return A node path.
 *
 */

#include "../../../inc/core.h"

t_nodes	graph_edge_backtrack(
	t_parray *edges,
	const char *t_key,
	t_ssize (*f)(t_graph_edge *))
{
	t_nodes			path;
	t_graph_node	*v;
	t_graph_edge	*e;
	t_size			i;

	e = parr_get_last(edges);
	if ((t_key && s_cmp(t_key, e->v->key)) || (f && !f(e)))
		return ((t_parray){NULL, 0, 0});
	path = parr_new(edges->len);
	v = e->u;
	parr_add_mult(&path, 2, e->u, e->v);
	i = edges->len;
	while (i--)
	{
		e = parr_get(edges, i);
		if (s_cmp(e->v->key, v->key) == 0)
		{
			if (f && (f(e) < 0))
				return (path);
			parr_add_first(&path, e->u);
			v = e->u;
		}
	}
	return (path);
}
