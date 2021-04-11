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

int	graph_contains_edge(t_graph *graph, char *v1_id, char *v2_id)
{
	t_vertex	*v1;
	t_vertex	*v2;
	size_t		i;

	v1 = array_get_vertex(graph->vertices, v1_id);
	if (v1 == NULL || v1->adj_list == NULL)
		return (0);
	i = 0;
	while (i < array_size(v1->adj_list))
	{
		v2 = *(t_vertex **)array_get(v1->adj_list, i);
		if (ft_strcmp(v2->id, v2_id) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	graph_add_edge(t_graph *graph, char *v1_id, char *v2_id)
{
	t_vertex	*v1;
	t_vertex	*v2;

	v1 = array_get_vertex(graph->vertices, v1_id);
	v2 = array_get_vertex(graph->vertices, v2_id);
	if (v1 == NULL || v2 == NULL)
		return (0);
	if (graph_contains_edge(graph, v1_id, v2_id))
		return (0);
	if (v1->adj_list == NULL)
	{
		v1->adj_list = array_new(INIT_SIZE, sizeof(t_vertex *));
		if (v1->adj_list == NULL)
			return (-1);
	}
	array_add(&v1->adj_list, (void *)&v2);
	if (v1->adj_list == NULL)
		return (-1);
	graph->edge_count += 1;
	return (1);
}
