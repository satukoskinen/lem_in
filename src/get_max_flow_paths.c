#include <stdlib.h>
#include "lem_in.h"
#include "libft.h"

static t_vertex	*get_next_vertex(t_vertex *vertex)
{
	t_edge	*adj_edge;
	t_edge	*edge;
	size_t	i;

	i = 0;
	while (i < array_size(vertex->adj_list))
	{
		adj_edge = *(t_edge **)array_get(vertex->adj_list, i);
		edge = graph_get_edge(adj_edge->dst->out, vertex->in);
		if (edge->flow > 0)
			return (adj_edge->dst);
		i++;
	}
	return (NULL);
}

static t_array	*save_flow_path(t_graph *graph, t_vertex *src,
t_vertex *sink, t_vertex *sink_adj)
{
	t_array		*path;
	t_vertex	*vertex;

	path = array_new(graph->vertex_count, sizeof(t_vertex *));
	if (path == NULL)
		return (NULL);
	array_add(&path, &sink);
	array_add(&path, &sink_adj);
	vertex = sink_adj;
	while (1)
	{
		vertex = get_next_vertex(vertex);
		if (vertex == NULL)
			break ;
		array_add(&path, &vertex);
		if (ft_strcmp(vertex->id, src->id) == 0)
			return (path);
	}
	array_del(&path);
	return (NULL);
}

static t_array	*save_flow_paths(t_graph *graph, t_vertex *src,
t_vertex *sink, size_t count)
{
	t_array	*paths;
	t_array	*path;
	t_edge	*sink_adj_edge;
	t_edge	*incoming_edge;
	size_t	i;

	paths = array_new(count, sizeof(t_array *));
	if (paths == NULL)
		return (NULL);
	i = 0;
	while (i < array_size(sink->adj_list))
	{
		sink_adj_edge = *(t_edge **)array_get(sink->adj_list, i);
		incoming_edge = graph_get_edge(sink_adj_edge->dst->out, sink->in);
		if (incoming_edge->flow > 0)
		{
			path = save_flow_path(graph, src, sink, sink_adj_edge->dst);
			if (path == NULL)
				break ;
			insert_path_to_array(&paths, &path);
		}
		i++;
	}
	if (path == NULL)
		array_del(&paths);
	return (paths);
}

t_array	*get_max_flow_paths(t_graph *graph)
{
	int		max_flow;
	t_array	*paths;

	max_flow = max_flow_edmonds_karp(graph, graph->source, graph->sink);
	if (max_flow <= 0)
		return (NULL);
	paths = save_flow_paths(graph, graph->source, graph->sink, (size_t)max_flow);
	return (paths);
}
