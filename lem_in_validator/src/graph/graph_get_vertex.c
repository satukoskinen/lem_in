#include "graph.h"
#include "libft.h"

t_vertex	*graph_get_vertex(t_graph *graph, char *id)
{
	t_vertex	*vertex;
	size_t		i;

	if (graph == NULL || graph->vertices == NULL)
		return (NULL);
	i = 0;
	while (i < array_size(graph->vertices))
	{
		vertex = *(t_vertex **)array_get(graph->vertices, i);
		if (ft_strcmp(vertex->id, id) == 0)
			return (vertex);
		i++;
	}
	return (NULL);
}
