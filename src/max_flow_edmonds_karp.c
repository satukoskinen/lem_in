#include "lem_in.h"

ssize_t	lem_compare_nodes(t_graph_node *n1, t_graph_node *n2)
{
	if (n1->id == n2->id)
		return (1);
	return (0);
}

ssize_t	update_edge_flows(t_array *edge_list, t_graph_node *sink)
{
	t_graph_node	*curr_node;
	t_graph_edge	*curr_edge;
	t_graph_edge	*rev_edge;
	size_t			i;

	curr_edge = arr_get_last(edge_list);
	if (!curr_edge || !lem_compare_nodes(sink, curr_edge->dst))
		return (0);
	curr_node = curr_edge->dst;
	i = edge_list->len;
	while (i--)
	{
		curr_edge = arr_get(edge_list, i);
		if (curr_edge->dst->id == curr_node->id)
		{
			((t_edge_attr *)curr_edge->attr)->flow += 1;
			rev_edge = get_edge(curr_edge->dst, curr_edge->src);
			((t_edge_attr *)rev_edge->attr)->flow -= 1;
			curr_node = curr_edge->src;
		}
	}
	return (1);
}

static ssize_t	edge_remaining_capacity(t_graph_edge *edge)
{
	t_edge_attr	*attr;

	attr = (t_edge_attr *)edge->attr;
	return (attr->capacity - attr->flow);
}

ssize_t	lem_find_node(t_array *dst, t_graph_node *node)
{
	size_t			i;
	t_graph_node	*cast;

	i = 0;
	cast = (t_graph_node *)dst->data;
	while (i < dst->len)
	{
		if (cast[i].id ==  node->id)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

static ssize_t graph_bfs_loop(
		t_array *bfs_queue,
		t_array *res_edges,
		t_graph_node *sink,
		size_t queue_index)
{
	t_graph_node	*curr_node;
	t_graph_edge	*curr_edge;
	size_t			i;

	if (bfs_queue->len == queue_index)
		return (CR_STOP);
	curr_node = arr_get(bfs_queue, queue_index);
	i = 0;
	while (i < curr_node->out.len)
	{
		curr_edge = arr_get(&curr_node->out, i);
		if (edge_remaining_capacity(curr_edge) > 0
		&& !lem_find_node(bfs_queue, curr_edge->dst))
		{
			if (!(arr_add_last(res_edges, curr_edge)))
				return (CR_FAIL);
			if (!(arr_add_last(bfs_queue, curr_edge->dst)))
				return (CR_FAIL);
			if (sink && curr_edge->dst->id == sink->id)
				return (CR_SUCCESS);
		}
		curr_node = arr_get(bfs_queue, queue_index);
		i++;
	}
	return (graph_bfs_loop(bfs_queue, res_edges, sink, queue_index + 1));
}

ssize_t new_augmenting_flow(
		t_array *res_edges,
		t_graph_node *src,
		t_graph_node *dst)
{
	t_array			bfs_queue;

	bfs_queue = arr_new(1, sizeof(t_graph_node));
	if (!(arr_add_last(&bfs_queue, src)))
		return (0);
	if (!(graph_bfs_loop(&bfs_queue, res_edges, dst, 0)))
		return (0);
	arr_free(&bfs_queue);
	return (1);
}

int64_t	max_flow_edmonds_karp(
	t_array *path_combinations,
	t_graph_node *s,
	t_graph_node *t)
{
	int64_t	flow;
	t_array	edge_list;
	t_array	paths;

	flow = 0;
	while (1)
	{
		edge_list = arr_new(1, sizeof(t_graph_edge));
		new_augmenting_flow(&edge_list, s, t);
		if (!update_edge_flows(&edge_list, t))
			break ;
		flow++;
		paths = save_max_flow_paths(s, t, (size_t)flow);
		arr_add_last(path_combinations, &paths);
		arr_free(&edge_list);
	}
	return (flow);
}

t_array	find_max_flow_paths(t_graph *graph)
{
	int64_t			max_flow;
	t_graph_node	*source;
	t_graph_node	*sink;
	t_array			path_combinations;

	source = ((t_graph_attr *)graph->attr)->source;
	sink = ((t_graph_attr *)graph->attr)->sink;
	path_combinations = arr_new(1, sizeof(t_array));
	max_flow = max_flow_edmonds_karp(&path_combinations, source, sink);
	if (max_flow <= 0)
		return (CR_ARR_NULL);
	return (path_combinations);
}
