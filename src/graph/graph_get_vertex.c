#include "graph.h"
#include "libft.h"

t_vertex	*graph_get_vertex(t_graph *graph, char *id)
{
	t_vertex	*vertex;
	size_t		i;

	if (graph == NULL || graph->vertices == NULL)
		return (NULL);
	i = 0;
	vertex = (t_vertex *)array_get(graph->vertices, i);
	while (vertex != NULL)
	{
		if (ft_strcmp(vertex->id, id) == 0)
			break ;
		i++;
		vertex = (t_vertex *)array_get(graph->vertices, i);
	}
	return (vertex);
}
