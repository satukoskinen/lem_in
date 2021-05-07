#include "lem_in.h"
#include "libft.h"

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
	t_graph_edge	*adj_edge;
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
			adj_edge = arr_get(&node->out, i);
			if (!map_contains_key(prev, adj_edge->dst->key)
				&& edge_remaining_capacity(adj_edge) > 0)
			{
				map_add(prev, node, adj_edge->dst->key);
				if (ft_strcmp(adj_edge->dst->key, t->key) == 0)
				{
					free(queue.data);
					return (1);
				}
				parr_add_last(&queue, adj_edge->dst);
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

int	find_max_flow_paths(t_graph *graph, t_graph_node *s, t_graph_node *t)
{
	int	max_flow;

	if (graph)
		;
	max_flow = max_flow_edmonds_karp(s, t);
	ft_printf("max flow is %d\n", max_flow);
	return (max_flow);
}
