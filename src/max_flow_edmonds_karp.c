#include "lem_in.h"
#include "libft.h"

static int	check_adjacent_vertices(t_graph *graph, t_array *queue,
t_vertex *vertex, t_vertex *dst)
{
	t_vertex	*adjacent;
	t_edge		*edge;
	size_t		i;

	i = 0;
	while (i < array_size(vertex->adj_list))
	{
		adjacent = *(t_vertex **)array_get(vertex->adj_list, i);
		edge = graph_get_edge(graph, vertex->out->id, adjacent->in->id);
		if (adjacent->prev == NULL && edge->flow < edge->capacity)
		{
			adjacent->prev = vertex;
			if (ft_strcmp(adjacent->id, dst->id) == 0)
			{
				array_del(&queue);
				return (1);
			}
			array_add(&queue, &adjacent);
		}
		i++;
	}
	return (0);
}

static int	find_augmenting_flow(t_graph *graph, t_vertex *src, t_vertex *dst)
{
	t_array		*queue;
	t_vertex	*vertex;
	int			reached_dst;

	queue = array_new(graph->vertex_count, sizeof(t_vertex *));
	if (queue == NULL)
		return (0);
	src->prev = src;
	array_add(&queue, &src);
	while (array_size(queue) > 0)
	{
		vertex = *(t_vertex **)array_get(queue, 0);
		array_remove(queue, 0);
		reached_dst = check_adjacent_vertices(graph, queue, vertex, dst);
		if (reached_dst)
			return (1);
	}
	array_del(&queue);
	return (0);
}

static void	reset_graph_paths(t_graph *graph)
{
	size_t		i;
	t_vertex	*vertex;

	i = 0;
	while (i < array_size(graph->vertices))
	{
		vertex = (t_vertex *)array_get(graph->vertices, i);
		vertex->prev = NULL;
		i++;
	}
}

static void	update_edge_flow(t_graph *graph, t_vertex *src, t_vertex *dst,
int delta_flow)
{
	t_edge	*edge;

	edge = graph_get_edge(graph, src->out->id, dst->in->id);
	edge->flow = edge->flow + delta_flow;
}

/*
** calculate the max flow of the network
*/

int	max_flow_edmonds_karp(t_graph *graph, t_vertex *src, t_vertex *dst)
{
	int			flow;
	int			augment_flow;
	t_vertex	*vertex;

	flow = 0;
	while (1)
	{
		reset_graph_paths(graph);
		augment_flow = find_augmenting_flow(graph, src, dst);
		if (augment_flow <= 0)
			break ;
		flow += augment_flow;
		vertex = dst;
		while (ft_strcmp(vertex->id, src->id) != 0)
		{
			update_edge_flow(graph, vertex->prev, vertex, augment_flow);
			update_edge_flow(graph, vertex, vertex->prev, -augment_flow);
			vertex = vertex->prev;
		}
	}
	if (augment_flow == -1)
		return (-1);
	else
		return (flow);
}
