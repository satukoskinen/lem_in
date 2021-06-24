#include "graph.h"
#include "libft.h"
#include <stdlib.h>

int	graph_contains_vertex(t_graph *graph, char *id)
{
	if (graph_get_vertex(graph, id) == NULL)
		return (0);
	else
		return (1);
}

void	init_vertex(t_vertex *vertex, char *id, int value, int capacity)
{
	vertex->id = id;
	vertex->value = value;
	if (vertex->capacity != -1)
		vertex->has_capacity = 1;
	else
		vertex->has_capacity = 0;
	vertex->capacity = capacity;
	vertex->dist = -1;
	vertex->is_sink = 0;
	vertex->is_source = 0;
	vertex->adj_list = NULL;
	vertex->prev = NULL;
	vertex->in = NULL;
	vertex->out = NULL;
}

t_vertex	*vertex_new(char *id, int value, int capacity)
{
	t_vertex	*vertex;

	if (id == NULL)
		return (NULL);
	vertex = (t_vertex *)malloc(sizeof(t_vertex));
	if (vertex == NULL)
		return (NULL);
	vertex->id = id;
	vertex->value = value;
	if (vertex->capacity != -1)
		vertex->has_capacity = 1;
	else
		vertex->has_capacity = 0;
	vertex->capacity = capacity;
	vertex->dist = -1;
	vertex->is_sink = 0;
	vertex->is_source = 0;
	vertex->adj_list = NULL;
	vertex->prev = NULL;
	vertex->in = NULL;
	vertex->out = NULL;
	return (vertex);
}

void	free_vertex(t_vertex *vertex)
{
	free(vertex->id);
	free(vertex->in->id);
	free(vertex->in);
	free(vertex->out->id);
	free(vertex->out);
	free(vertex);
}

int	graph_add_vertex(t_graph *graph, char *id, int value, int capacity)
{
	t_vertex	*vertex;

	if (graph_contains_vertex(graph, id))
		return (0);
	id = ft_strdup(id);
	if (id == NULL)
		return (-1);
	vertex = vertex_new(id, value, capacity);
	vertex->in = vertex_new(ft_strjoin(id, "_in"), value, -1);
	vertex->out = vertex_new(ft_strjoin(id, "_out"), value, -1);
	if (vertex->in == NULL || vertex->out == NULL)
		return (-1);
	array_add(&graph->vertices, &vertex);
	if (graph->vertices == NULL)
	{
		free_vertex(vertex);
		return (-1);
	}
	graph->vertex_count += 1;
	graph_add_inner_edge(graph, id, 1);
	return (1);
}
