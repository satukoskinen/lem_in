#include "lem_in.h"

ssize_t	update_edge(t_graph_edge *e)
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

static ssize_t	update_edge_flows(t_parray *edge_list, t_graph_node *t)
{
	t_nodes	res;

	res = graph_edge_backtrack(edge_list, t->key, update_edge);
	if (arr_null(&res))
		return (false);
	arr_free(&res);
	return (true);
}

static int64_t	max_flow_edmonds_karp(
	t_graph *graph,
	const char *s_key,
	const char *t_key,
	t_array *path_combinations)
{
	int64_t			flow;
	t_parray		edge_list;
	t_array			paths;
	t_graph_node	*s;
	t_graph_node	*t;

	s = graph_find_node(graph, s_key);
	t = graph_find_node(graph, t_key);
	flow = 0;
	while (1)
	{
		edge_list = graph_bfs(graph, s_key, t_key);
		if (edge_list.len == 0 || !update_edge_flows(&edge_list, t))
			break ;
		flow++;
		paths = lem_save_max_flow_paths(s, t, (size_t)flow);
		arr_add_last(path_combinations, &paths);
		parr_free(&edge_list);
	}
	parr_free(&edge_list);
	return (flow);
}

t_paths	lem_find_max_flow_paths(t_lem *lem)
{
	int64_t	max_flow;
	t_array	path_combinations;

	path_combinations = arr_new(1, sizeof(t_array));
	max_flow = max_flow_edmonds_karp(&lem->graph,
		lem->s_key, lem->t_key, &path_combinations);
	if (max_flow <= 0)
	{
		arr_free(&path_combinations);
		return (CR_ARR_NULL);
	}
	return (path_combinations);
}
