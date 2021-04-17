#include "graph.h"
#include "libft.h"
#include <stdlib.h>

static t_vertex	*array_get_vertex(t_array *array, char *v_id)
{
	t_vertex	*vertex;
	size_t		i;

	if (array == NULL)
		return (NULL);
	i = 0;
	vertex = (t_vertex *)array_get(array, i);
	while (vertex != NULL)
	{
		if (ft_strcmp(vertex->id, v_id) == 0)
			break ;
		i++;
		vertex = (t_vertex *)array_get(array, i);
	}
	return (vertex);
}

int	graph_contains_vertex(t_graph *graph, char *v_id)
{
	if (array_get_vertex(graph->vertices, v_id) == NULL)
		return (0);
	else
		return (1);
}

t_vertex	*vertex_new(char *id, int value, int capacity)
{
	t_vertex *vertex;

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

int	graph_add_vertex(t_graph *graph, char *id, int value, int capacity)
{
	t_vertex	*vertex;

	if (graph_contains_vertex(graph, id))
		return (0);
	vertex = vertex_new(ft_strdup(id), value, capacity);
	if (vertex == NULL)
		return (-1);
	vertex->in = vertex_new(ft_strjoin(id, "_in"), value, -1);
	vertex->out = vertex_new(ft_strjoin(id, "_out"), value, -1);
	if (vertex->in == NULL || vertex->out == NULL)
		return (-1);
	array_add(&graph->vertices, vertex);
	if (graph->vertices == NULL)
	{
		free(vertex->id);
		free(vertex->in->id);
		free(vertex->in);
		free(vertex->out->id);
		free(vertex->out);
		free(vertex);
		return (-1);
	}
	free(vertex);
	graph->vertex_count += 1;
	return (1);
}
