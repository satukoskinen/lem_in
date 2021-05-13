#include "lem_in.h"

// static ssize_t	update_edge_flows(t_array *edge_list, t_graph_node *sink)
// {
// 	t_graph_node	*curr_node;
// 	t_graph_edge	*curr_edge;
// 	t_graph_edge	*rev_edge;
// 	size_t			i;

// 	curr_edge = arr_get_last(edge_list);
// 	if (!curr_edge || !lem_compare_nodes(sink, curr_edge->dst))
// 		return (0);
// 	curr_node = curr_edge->dst;
// 	i = edge_list->len;
// 	while (i--)
// 	{
// 		curr_edge = arr_get(edge_list, i);
// 		if (curr_edge->dst->id == curr_node->id)
// 		{
// 			((t_edge_attr *)curr_edge->attr)->flow += 1;
// 			rev_edge = lem_get_edge(curr_edge->dst, curr_edge->src);
// 			((t_edge_attr *)rev_edge->attr)->flow -= 1;
// 			curr_node = curr_edge->src;
// 		}
// 	}
// 	return (1);
// }

// static ssize_t	graph_bfs_loop(
// 		t_array *bfs_queue,
// 		t_array *res_edges,
// 		t_graph_node *sink,
// 		size_t queue_index)
// {
// 	t_graph_node	*curr_node;
// 	t_graph_edge	*curr_edge;
// 	size_t			i;

// 	if (bfs_queue->len == queue_index)
// 		return (CR_STOP);
// 	curr_node = arr_get(bfs_queue, queue_index);
// 	i = 0;
// 	while (i < curr_node->out.len)
// 	{
// 		curr_edge = arr_get(&curr_node->out, i);
// 		if (lem_edge_remaining_capacity(curr_edge) > 0
// 			&& !lem_find_node(bfs_queue, curr_edge->dst))
// 		{
// 			arr_add_last(res_edges, curr_edge);
// 			arr_add_last(bfs_queue, curr_edge->dst);
// 			if (sink && curr_edge->dst->id == sink->id)
// 				return (CR_SUCCESS);
// 		}
// 		curr_node = arr_get(bfs_queue, queue_index);
// 		i++;
// 	}
// 	return (graph_bfs_loop(bfs_queue, res_edges, sink, queue_index + 1));
// }

// static ssize_t	new_augmenting_flow(
// 		t_array *res_edges,
// 		t_graph_node *src,
// 		t_graph_node *dst)
// {
// 	t_array	bfs_queue;

// 	bfs_queue = arr_new(1, sizeof(t_graph_node));
// 	arr_add_last(&bfs_queue, src);
// 	if (!(graph_bfs_loop(&bfs_queue, res_edges, dst, 0)))
// 	{
// 		arr_free(&bfs_queue);
// 		return (0);
// 	}
// 	arr_free(&bfs_queue);
// 	return (1);
// }

ssize_t	update_edge(t_graph_edge *e)
{
	t_graph_edge	*rev_e;

	((t_edge_attr *)e->attr)->flow += 1;
	rev_e = lem_get_edge(e->v, e->u);
	((t_edge_attr *)rev_e->attr)->flow -= 1;
	if (((t_edge_attr *)e->attr)->flow == 0)
		e->valid = 0;
	if (((t_edge_attr *)rev_e->attr)->flow == 0)
		rev_e->valid = 0;
	return (1);
}

static ssize_t	update_edge_flows(t_edges *edge_list, t_graph_node *t)
{
	t_nodes	res;

	res = graph_edge_backtrack(edge_list, t->key, update_edge);
	if (arr_null(&res))
		return (false);
	arr_free(&res);
	return (true);
}

static int64_t	max_flow_edmonds_karp(
	t_lem *lem,
	t_array *path_combinations)
{
	int64_t	flow;
	t_array	edge_list;
	t_array	paths;

	flow = 0;
	while (1)
	{
		edge_list = graph_bfs(&lem->graph, lem->s_key, lem->t_key);
		if (!update_edge_flows(&edge_list, graph_find_node(&lem->graph, lem->t_key)))
			break ;
		flow++;
		paths = lem_save_max_flow_paths(graph_find_node(&lem->graph, lem->s_key), graph_find_node(&lem->graph, lem->t_key), (size_t)flow);
		arr_add_last(path_combinations, &paths);
		arr_free(&edge_list);
	}
	arr_free(&edge_list);
	return (flow);
}

t_paths	lem_find_max_flow_paths(t_lem *lem)
{
	int64_t			max_flow;
	t_array			path_combinations;

	path_combinations = arr_new(1, sizeof(t_array));
	max_flow = max_flow_edmonds_karp(lem, &path_combinations);
	if (max_flow <= 0)
	{
		arr_free(&path_combinations);
		return (CR_ARR_NULL);
	}
	return (path_combinations);
}
