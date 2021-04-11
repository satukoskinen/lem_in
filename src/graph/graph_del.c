#include "graph.h"
#include "libft.h"
#include <stdlib.h>

void	graph_del(t_graph **graph)
{
	size_t		i;
	t_vertex	*vertex;

	i = 0;
	while (i < array_size((*graph)->vertices))
	{
		vertex = (t_vertex *)array_get((*graph)->vertices, i);
		free(vertex->id);
		if (vertex->adj_list != NULL)
			array_del(&vertex->adj_list);
		i++;
	}
	array_del(&(*graph)->vertices);
	free(*graph);
	*graph = NULL;
}
