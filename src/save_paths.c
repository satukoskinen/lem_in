#include "lem_in.h"
#include "libft.h"

t_array	*save_prev_path(t_graph *graph, t_vertex *src, t_vertex *sink)
{
	t_array		*path;
	t_vertex	*vertex;

	if (src == NULL || sink == NULL)
		return (NULL);
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

t_array	*save_flow_path(t_graph *graph, t_vertex *src, t_vertex *sink, t_vertex *sink_adj)
{
	t_array		*path;
	t_vertex	*vertex;
	t_vertex	*adj;
	t_edge		*edge;
	size_t		i;

	if (src == NULL || sink == NULL || sink_adj == NULL)
		return (NULL);
	path = array_new(graph->vertex_count, sizeof(t_vertex *));
	if (path == NULL)
		return (NULL);
	array_add(&path, &sink);
	array_add(&path, &sink_adj);
	vertex = sink_adj;
	while (1)
	{
		i = 0;
		while (i < array_size(vertex->adj_list))
		{
			adj = *(t_vertex **)array_get(vertex->adj_list, i);
			edge = get_edge(graph, adj->out->id, vertex->in->id);
			if (edge->flow > 0)
			{
				array_add(&path, &adj);
				vertex = adj;
				i = 0;
				break ;
			}
			i++;
		}
		if (ft_strcmp(vertex->id, src->id) == 0)
			return (path);
		if (i == array_size(vertex->adj_list))
			break ;
	}
	array_del(&path);
	return (NULL);
}

t_array	*save_paths(t_graph *graph, t_vertex *src, t_vertex *sink, int count)
{
	t_array		*paths;
	t_array		*path;
	size_t		i;
	t_vertex	*sink_adj;
	t_edge		*edge;

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
		i = 0;
		while (i < array_size(sink->adj_list))
		{
			sink_adj = *(t_vertex **)array_get(sink->adj_list, i);
			edge = get_edge(graph, sink_adj->out->id, sink->in->id);
			if (edge->flow > 0)
			{
				path = save_flow_path(graph, src, sink, sink_adj);
				if (path == NULL)
				{
					array_del(&paths);
					return (NULL);
				}
				array_add(&paths, &path);
			}
			i++;
		}
	}
	return (paths);
}
