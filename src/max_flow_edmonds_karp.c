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
		edge = graph_get_edge(graph, vertex->id, adjacent->id);
		if (adjacent->prev == NULL && edge->flow < edge->capacity)
		{
			adjacent->prev = vertex;
			if (ft_strcmp(adjacent->id, dst->in->id) == 0)
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
	src->out->prev = src;
	array_add(&queue, &(src->out));
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
		vertex = *(t_vertex **)array_get(graph->vertices, i);
		vertex->prev = NULL;
		vertex->in->prev = NULL;
		vertex->out->prev = NULL;
		i++;
	}
}

/*
static void	update_edge_flow(t_graph *graph, t_vertex *src, t_vertex *dst,
int delta_flow)
{
	t_edge	*edge;
	char	*reverse_src_id;
	char	*reverse_dst_id;
	size_t	i;

	edge = graph_get_edge(graph, src->id, dst->id);
	edge->flow = edge->flow + delta_flow;
	reverse_src_id = ft_strdup(src->id);
	reverse_dst_id = ft_strdup(dst->id);
	i = ft_strlen(reverse_src_id) - 1;
	while (reverse_src_id[i] != '_')
		i--;
	if (ft_strncmp(reverse_dst_id, reverse_src_id, i) == 0)
	{
		edge = graph_get_edge(graph, dst->id, src->id);
		edge->flow = edge->flow - delta_flow;
	}
	else
	{
		reverse_src_id[i] = '\0';
		reverse_src_id = ft_strjoin(reverse_src_id, "_in");
		i = ft_strlen(reverse_dst_id) - 1;
		while (reverse_dst_id[i] != '_')
		i--;
		reverse_dst_id[i] = '\0';
		reverse_dst_id = ft_strjoin(reverse_dst_id, "_out");
		edge = graph_get_edge(graph, reverse_dst_id, reverse_src_id);
		edge->flow = edge->flow - delta_flow;
	}
}
*/

static void	update_edge_flow(t_graph *graph, t_vertex *src, t_vertex *dst,
int delta_flow)
{
	t_edge	*edge;

	edge = graph_get_edge(graph, src->id, dst->id);
	edge->flow = edge->flow + delta_flow;
	edge = graph_get_edge(graph, dst->id, src->id);
	edge->flow = edge->flow - delta_flow;
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
		vertex = dst->in;
		while (ft_strcmp(vertex->id, src->out->id) != 0)
		{
			update_edge_flow(graph, vertex->prev, vertex, augment_flow);
			vertex = vertex->prev;
		}
	}
	if (augment_flow == -1)
		return (-1);
	else
		return (flow);
}
