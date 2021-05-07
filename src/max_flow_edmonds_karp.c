#include "lem_in.h"
#include "libft.h"

void	save_flow_path(t_parr *path, t_graph_node *src, t_graph_node *dst)
{
	t_graph_node	*node;
	t_graph_edge	*edge;
	size_t			i;

	node = src;
	parr_add_last(path, node);
	while (ft_strcmp(node->key, dst->key) != 0)
	{
		i = 0;
		while (i < node->in.len)
		{
			edge = arr_get(&node->in, i);
			if (((t_edge_attr *)edge->attr)->flow > 0)
			{
				parr_add_last(path, edge->src);
				node = edge->src;
				break ;
			}
			i++;
		}
	}
}

t_array	save_max_flow_paths(t_graph_node *s, t_graph_node *t, size_t max_flow)
{
	t_array			paths;
	t_parr			path;
	size_t			i;
	t_graph_edge	*sink_edge;

	paths = arr_new(max_flow, sizeof(t_parr));
	if (paths.data == NULL)
		return (CR_ARR_NULL);
	i = 0;
	while (i < t->in.len)
	{
		sink_edge = arr_get(&t->in, i);
		if (((t_edge_attr *)sink_edge->attr)->flow > 0)
		{
			path = parr_new(sizeof(t_graph_node *));
			parr_add_last(&path, t);
			save_flow_path(&path, sink_edge->src, s);
			arr_add_last(&paths, &path);
		}
		i++;
	}
	return (paths);
}

int		map_contains_key(t_map *map, const char *key)
{
	if (map_get(map, key) == NULL)
		return (0);
	else
		return (1);
}

t_graph_edge	*graph_get_edge(t_graph_node *src, t_graph_node *dst)
{
	size_t			i;
	t_graph_edge	*edge;

	i = 0;
	while (i < src->out.len)
	{
		edge = arr_get(&src->out, i);
		if (ft_strcmp(edge->dst->key, dst->key) == 0)
			return (edge);
		i++;
	}
	return (NULL);
}

void	update_edge_flows(t_map *prev, t_graph_node *s, t_graph_node *t, int augmenting_flow)
{
	t_graph_node	*node;
	t_graph_node	*prev_node;
	t_graph_edge	*edge;

	node = t;
	while (ft_strcmp(node->key, s->key) != 0)
	{
		prev_node = map_get(prev, node->key);
		edge = graph_get_edge(prev_node, node);
		((t_edge_attr *)edge->attr)->flow += augmenting_flow;
		edge = graph_get_edge(node, prev_node);
		((t_edge_attr *)edge->attr)->flow -= augmenting_flow;
		node = prev_node;
	}
}

static ssize_t	edge_remaining_capacity(t_graph_edge *edge)
{
	return (((t_edge_attr *)edge->attr)->capacity - ((t_edge_attr *)edge->attr)->flow);
}

int	find_augmenting_flow(t_graph_node *s, t_graph_node *t, t_map *prev)
{
	t_parr			queue;
	t_graph_node	*node;
	t_graph_edge	*outgoing_edge;
	size_t			i;

	queue = parr_new(sizeof(t_graph_node *));
	map_add(prev, s, s->key);
	parr_add_last(&queue, s);
	while (queue.len > 0)
	{
		node = parr_take_first(&queue);
		i = 0;
		while (i < node->out.len)
		{
			outgoing_edge = arr_get(&node->out, i);
			if (!map_contains_key(prev, outgoing_edge->dst->key)
				&& edge_remaining_capacity(outgoing_edge) > 0)
			{
				map_add(prev, node, outgoing_edge->dst->key);
				if (ft_strcmp(outgoing_edge->dst->key, t->key) == 0)
				{
					free(queue.data);
					return (1);
				}
				parr_add_last(&queue, outgoing_edge->dst);
			}
			i++;
		}
	}
	free(queue.data);
	return (0);
}

int	max_flow_edmonds_karp(t_graph_node *s, t_graph_node *t)
{
	int		flow;
	int		augmenting_flow;
	t_map	prev;

	flow = 0;
	while (1)
	{
		prev = map_new();
		augmenting_flow = find_augmenting_flow(s, t, &prev);
		if (augmenting_flow <= 0)
			break ;
		update_edge_flows(&prev, s, t, augmenting_flow);
		flow += augmenting_flow;
		free(prev.node);
	}
	if (augmenting_flow == -1)
		return (-1);
	else
		return (flow);
}

t_array	find_max_flow_paths(t_graph *graph)
{
	int		max_flow;
	t_array	paths;

	max_flow = max_flow_edmonds_karp(
		((t_graph_attr *)graph->attr)->source,
		((t_graph_attr *)graph->attr)->sink);
	if (max_flow <= 0)
		return (CR_ARR_NULL);
	paths = save_max_flow_paths(
		((t_graph_attr *)graph->attr)->source,
		((t_graph_attr *)graph->attr)->sink,
		(size_t)max_flow);
	ft_printf("max flow is %d\n", max_flow);
	return (paths);
}
