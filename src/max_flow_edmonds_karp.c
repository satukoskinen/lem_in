#include "lem_in.h"
#include "libft.h"

int	find_shortest_path_flow(t_graph *graph, t_vertex *src, t_vertex *dst)
{
	t_array		*queue;
	t_vertex	*vertex;
	t_vertex	*adjacent;
	t_edge		*edge;
	size_t		i;

	queue = array_new(INIT_SIZE, sizeof(t_vertex *));
	if (queue == NULL)
		return (0);
	src->prev = src;
	if (array_add(&queue, &src) == NULL)
	{
		array_del(&queue);
		return (-1);
	}
	while (array_size(queue) > 0)
	{
		vertex = *(t_vertex **)array_get(queue, 0);
		array_remove(queue, 0);
		i = 0;
		while (i < array_size(vertex->adj_list))
		{
			adjacent = *(t_vertex **)array_get(vertex->adj_list, i);
			edge = get_edge(graph, vertex->out->id, adjacent->in->id);
			if (adjacent->prev == NULL && edge->flow < edge->capacity)
			{
				adjacent->prev = vertex;
				if (ft_strcmp(adjacent->id, dst->id) == 0)
				{
					array_del(&queue);
					return (1);
				}
				if (array_add(&queue, &adjacent) == NULL)
				{
					array_del(&queue);
					return (-1);
				}
			}
			i++;
		}
	}
	array_del(&queue);
	return (0);
}

void	reset_graph_paths(t_graph *graph)
{
	size_t	i;
	t_vertex *vertex;

	i = 0;
	while (i < array_size(graph->vertices))
	{
		vertex = (t_vertex *)array_get(graph->vertices, i);
		vertex->prev = NULL;
		i++;
	}
}

void	update_edge_flow(t_graph *graph, char *src_id, char *dst_id,
int delta_flow)
{
	t_edge	*edge;

	edge = get_edge(graph, src_id, dst_id);
	edge->flow = edge->flow + delta_flow;
}

/*
** calculate the max flow of the network
*/

int	max_flow_edmonds_karp(t_vertex *src, t_vertex *dst, t_graph *graph)
{
	int			flow;
	int			augmenting_flow;
	t_vertex	*vertex;

	flow = 0;
	while (1)
	{
		reset_graph_paths(graph);
		augmenting_flow = find_shortest_path_flow(graph, src, dst);
		if (augmenting_flow <= 0)
			break ;
		flow += augmenting_flow;
		vertex = dst;
		while (ft_strcmp(vertex->id, src->id) != 0)
		{
//			ft_printf("update edge flow %s %s\n", vertex->prev->id, vertex->id);
			update_edge_flow(graph, vertex->prev->out->id,
				vertex->in->id, augmenting_flow);
			update_edge_flow(graph, vertex->out->id,
				vertex->prev->in->id, -augmenting_flow);
			vertex = vertex->prev;
		}
//		graph_print_edges(graph);
	}
	if (augmenting_flow == -1)
		return (-1);
	else
		return (flow);
}