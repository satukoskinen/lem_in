#include "lem_in.h"

/*
 *	Increase the given edge flow by 1 and decrease the flow if its
 *	reverse edge by 1, and then update the validity of both edges
 *	according to whether the edge flow < capacity.
 */

t_ssize	update_edge(t_graph_edge *e)
{
	t_graph_edge	*rev_e;

	((t_edge_attr *)e->attr)->flow += 1;
	rev_e = lem_get_edge(e->v, e->u);
	((t_edge_attr *)rev_e->attr)->flow -= 1;
	if (((t_edge_attr *)e->attr)->flow < ((t_edge_attr *)e->attr)->capacity)
		e->valid = 1;
	else
		e->valid = 0;
	if (((t_edge_attr *)rev_e->attr)->flow
		< ((t_edge_attr *)rev_e->attr)->capacity)
		rev_e->valid = 1;
	else
		rev_e->valid = 0;
	return (1);
}

/*
 *	Backtracks the edges in the edge list returned by the breadth first search
 *	and updated the edge flows. The updating function is passed as a function
 *	pointer to the core library function graph_edge_backtrack.
 */

static t_ssize	update_edge_flows(t_parray *edge_list, const char *t_key)
{
	t_nodes	res;

	res = graph_edge_backtrack(edge_list, t_key, update_edge);
	if (parr_null(&res))
		return (FALSE);
	parr_free(&res);
	return (TRUE);
}

/*
 *	Iterate a breadth first search over the network increasing the flow by
 *	1 each iteration. The breadth first search returns a list of edges that
 *	lead from sink to source. The loop continues until the breadth first seacrh
 *	doesn't return any more edges or if the edge list couldn't be track back to
 *	the source node. Calls lem_save_max_flow_paths which returns a list of paths
 *	associated with the corresponding flow. That combination of paths is then
 *	added to `path_combinations` for future porcessing.
 */

static t_int64	max_flow_edmonds_karp(
	t_graph *graph,
	const char *s_key,
	const char *t_key,
	t_parray *path_combinations)
{
	t_int64			flow;
	t_parray		edge_list;
	t_parray		*paths;
	t_graph_node	*s;
	t_graph_node	*t;

	s = graph_find_node(graph, s_key);
	t = graph_find_node(graph, t_key);
	flow = 0;
	while (1)
	{
		edge_list = graph_bfs(graph, s_key, t_key);
		if (edge_list.len == 0 || !update_edge_flows(&edge_list, t_key))
			break ;
		flow++;
		paths = lem_save_max_flow_paths(s, t, (t_size)flow);
		if (parr_add_last(path_combinations, paths) != 1)
			lem_exit_error("parr add last");
		parr_free(&edge_list);
	}
	parr_free(&edge_list);
	return (flow);
}

/*
 *	Constructs the max flow paths for a range of flows from
 *	0 to max flow. Returns an array of pointers to array of
 *	paths for different flows.
 */

t_parray	lem_find_max_flow_paths(t_lem *lem)
{
	t_int64		max_flow;
	t_parray	path_combinations;

	path_combinations = parr_new(1);
	if (parr_null(&path_combinations))
		lem_exit_error("parr null");
	max_flow = max_flow_edmonds_karp(&lem->graph,
		lem->s_key, lem->t_key, &path_combinations);
	if (max_flow <= 0)
	{
		parr_free(&path_combinations);
		return ((t_parray){NULL, 0, 0});
	}
	return (path_combinations);
}
