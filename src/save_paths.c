#include "lem_in.h"
#include "libft.h"

static t_vertex	*get_next_vertex(t_graph *graph, t_vertex *vertex)
{
	t_vertex	*adj;
	t_edge		*edge;
	size_t		i;

	i = 0;
	while (i < array_size(vertex->adj_list))
	{
		adj = *(t_vertex **)array_get(vertex->adj_list, i);
		edge = graph_get_edge(graph, adj->out->id, vertex->in->id);
		if (edge->flow > 0)
			return (adj);
		i++;
	}
	return (NULL);
}

static t_array	*save_flow_path(t_graph *graph, t_vertex *src, t_vertex *sink,
t_vertex *sink_adj)
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
		vertex = get_next_vertex(graph, vertex);
		if (vertex == NULL)
			break ;
		array_add(&path, &vertex);
		if (ft_strcmp(vertex->id, src->id) == 0)
			return (path);
	}
	array_del(&path);
	return (NULL);
}

static int	save_flow_paths(t_graph *graph, t_vertex *src, t_vertex *sink,
t_array **paths)
{
	t_array		*path;
	t_vertex	*sink_adj;
	t_edge		*edge;
	size_t		i;

	i = 0;
	while (i < array_size(sink->adj_list))
	{
		sink_adj = *(t_vertex **)array_get(sink->adj_list, i);
		edge = graph_get_edge(graph, sink_adj->out->id, sink->in->id);
		if (edge->flow > 0)
		{

			path = save_flow_path(graph, src, sink, sink_adj);
			if (path == NULL)
				return (0);
			array_add(paths, &path);
		}
		i++;
	}
	return (1);
}

static t_array	*save_prev_path(t_graph *graph, t_vertex *src, t_vertex *sink)
{
	t_array		*path;
	t_vertex	*vertex;

	path = array_new(graph->vertex_count, sizeof(t_vertex *));
	if (path == NULL)
		return (NULL);
	vertex = sink;
	while (vertex != NULL)
	{
		if (array_add(&path, &vertex) == NULL)
			return (NULL);
		vertex = vertex->prev;
	}
	vertex = *(t_vertex **)array_get(path, array_size(path) - 1);
	if (ft_strcmp(src->id, vertex->id) != 0)
	{
		array_del(&path);
		return (NULL);
	}
	return (path);
}

t_array	*save_paths(t_graph *graph, t_vertex *src, t_vertex *sink, int count)
{
	t_array		*paths;
	t_array		*path;
	int			ret;

	paths = array_new(count, sizeof(t_array *));
	if (paths == NULL)
		return (NULL);
	if (sink->prev != NULL)
	{
		path = save_prev_path(graph, src, sink);
		if (path == NULL)
		{
			array_del(&paths);
			return (NULL);
		}
		array_add(&paths, &path);
	}
	else
	{
		ret = save_flow_paths(graph, src, sink, &paths);
		if (ret == 0)
			array_del(&paths);
	}
	return (paths);
}
