#include "lem_in.h"
#include "libft.h"

void	update_edge_flows(t_map *prev, t_graph_node *s, t_graph_node *t,
	int augmenting_flow)
{
	t_graph_node	*node;
	t_graph_node	*prev_node;
	t_graph_edge	*edge;

	node = t;
	while (ft_strcmp(node->key, s->key) != 0)
	{
		prev_node = map_get(prev, node->key);
		edge = get_edge(prev_node, node);
		((t_edge_attr *)edge->attr)->flow += augmenting_flow;
		edge = get_edge(node, prev_node);
		((t_edge_attr *)edge->attr)->flow -= augmenting_flow;
		node = prev_node;
	}
}

static ssize_t	edge_remaining_capacity(t_graph_edge *edge)
{
	t_edge_attr	*attr;

	attr = (t_edge_attr *)edge->attr;
	return (attr->capacity - attr->flow);
}

int	find_augmenting_flow(t_graph_node *s, t_graph_node *t, t_map *prev)
{
	t_parray		queue;
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
			if (edge_remaining_capacity(outgoing_edge) > 0
				&& !map_contains_key(prev, outgoing_edge->dst->key))
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

int	max_flow_edmonds_karp(t_graph_node *s, t_graph_node *t,
	t_array *path_combinations)
{
	int		flow;
	int		augmenting_flow;
	t_map	prev;
	t_array	paths;

	flow = 0;
	while (1)
	{
		prev = map_new();
		augmenting_flow = find_augmenting_flow(s, t, &prev);
		if (augmenting_flow <= 0)
			break ;
		update_edge_flows(&prev, s, t, augmenting_flow);
		flow += augmenting_flow;
		paths = save_max_flow_paths(s, t, (size_t)flow);
		arr_add_last(path_combinations, &paths);
		free(prev.node);
	}
	if (augmenting_flow == -1)
		return (-1);
	else
		return (flow);
}

t_array	find_max_flow_paths(t_graph *graph)
{
	int				max_flow;
	t_graph_node	*source;
	t_graph_node	*sink;
	t_array			path_combinations;

	source = ((t_graph_attr *)graph->attr)->source;
	sink = ((t_graph_attr *)graph->attr)->sink;
	path_combinations = arr_new(1, sizeof(t_array));
	max_flow = max_flow_edmonds_karp(source, sink, &path_combinations);
	if (max_flow <= 0)
		return (CR_ARR_NULL);
	return (path_combinations);
}
