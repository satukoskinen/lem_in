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

int	graph_add_vertex(t_graph *graph, char *id, int value)
{
	t_vertex	vertex;

	if (graph_contains_vertex(graph, id))
		return (0);
	vertex.id = ft_strdup(id);
	if (vertex.id == NULL)
		return (-1);
	vertex.value = value;
	vertex.dist = -1;
	vertex.is_sink = 0;
	vertex.is_source = 0;
	vertex.adj_list = NULL;
	vertex.prev = NULL;
	array_add(&graph->vertices, &vertex);
	if (graph->vertices == NULL)
	{
		free(vertex.id);
		return (-1);
	}
	graph->vertex_count += 1;
	return (1);
}
