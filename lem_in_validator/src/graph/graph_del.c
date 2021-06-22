#include "graph.h"
#include "libft.h"
#include <stdlib.h>

void	graph_del(t_graph **graph)
{
	t_size		i;
	t_vertex	*vertex;

	i = 0;
	while (i < array_size((*graph)->vertices))
	{
		vertex = *(t_vertex **)array_get((*graph)->vertices, i);
		free(vertex->id);
		free(vertex->in->id);
		array_del(&(vertex->in->adj_list));
		free(vertex->in);
		free(vertex->out->id);
		array_del(&(vertex->out->adj_list));
		free(vertex->out);
		free(vertex);
		if (vertex->adj_list != NULL)
			array_del(&vertex->adj_list);
		i++;
	}
	array_del(&(*graph)->vertices);
	array_del(&(*graph)->edges);
	free(*graph);
	*graph = NULL;
}
