#include "graph.h"
#include "libft.h"
#include <stdlib.h>

void	graph_del(t_graph **graph)
{
	size_t		i;
	t_vertex	*vertex;
	t_edge		*edge;

	i = 0;
	while (i < array_size((*graph)->vertices))
	{
		vertex = *(t_vertex **)array_get((*graph)->vertices, i);
		free(vertex->id);
		free(vertex->in->id);
		if (vertex->in->adj_list != NULL)
			array_del(&(vertex->in->adj_list));
		free(vertex->in);
		free(vertex->out->id);
		if (vertex->out->adj_list != NULL)
			array_del(&(vertex->out->adj_list));
		free(vertex->out);
		if (vertex->adj_list != NULL)
			array_del(&vertex->adj_list);
		free(vertex);
		i++;
	}
	array_del(&(*graph)->vertices);
	i = 0;
	while (i < array_size((*graph)->edges))
	{
		edge = *(t_edge **)array_get((*graph)->edges, i);
		free(edge);
		i++;
	}
	array_del(&(*graph)->edges);
	free(*graph);
	*graph = NULL;
}
