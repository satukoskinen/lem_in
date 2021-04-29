#include <stdlib.h>
#include "lem_in.h"
#include "libft.h"

static t_array	*save_prev_path(t_graph *graph, t_vertex *src,
t_vertex *sink, t_vertex *sink_adj)
{
	t_array		*path;
	t_vertex	*vertex;

	path = array_new(graph->vertex_count, sizeof(t_vertex *));
	if (path == NULL)
		return (NULL);
	array_add(&path, &sink);
	vertex = sink_adj;
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

static t_array	*save_shortest_paths(t_graph *graph, t_vertex *src,
t_vertex *sink, size_t count)
{
	t_array	*paths;
	t_array	*path;
	t_edge	*sink_adj_edge;
	size_t	i;

	paths = array_new(count, sizeof(t_array *));
	if (paths == NULL)
		return (NULL);
	i = 0;
	while (i < array_size(sink->adj_list))
	{
		sink_adj_edge = *(t_edge **)array_get(sink->adj_list, i);
		if (sink_adj_edge->dst->prev != NULL)
		{
			path = save_prev_path(graph, src, sink, sink_adj_edge->dst);
			if (path == NULL)
			{
				array_del(&paths);
				return (NULL);
			}
			insert_path_to_array(&paths, &path);
		}
		i++;
	}
	return (paths);
}

static void	reset_vertex_values(t_graph *graph, t_vertex *sink)
{
	size_t		i;
	t_vertex	*vertex;

	vertex = sink;
	while (vertex->prev != NULL)
	{
		vertex->dist = 0;
		vertex = vertex->prev;
	}
	i = 0;
	while (i < array_size(graph->vertices))
	{
		vertex = *(t_vertex **)array_get(graph->vertices, i);
		if (vertex->dist != 0)
		{
			vertex->dist = -1;
			vertex->prev = NULL;
		}
		i++;
	}
}

t_array	*get_shortest_paths(t_graph *graph)
{
	int		path_len;
	t_array	*paths;

	path_len = find_shortest_path(graph, graph->source, graph->sink);
	if (path_len == -1)
		return (NULL);
	while (1)
	{
		reset_vertex_values(graph, graph->sink);
		path_len = find_shortest_path(graph, graph->source, graph->sink);
		if (path_len <= 0)
			break ;
	}
	paths = save_shortest_paths(graph, graph->source, graph->sink, 1);
	return (paths);
}
