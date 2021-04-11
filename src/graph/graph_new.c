#include "graph.h"
#include "libft.h"
#include <stdlib.h>

t_graph	*graph_new(void)
{
	t_graph	*graph;

	graph = (t_graph *)malloc(sizeof(t_graph));
	if (graph == NULL)
		return (NULL);
	graph->vertices = array_new(INIT_SIZE, sizeof(t_vertex));
	if (graph->vertices == NULL)
	{
		free(graph);
		return (NULL);
	}
	graph->source = NULL;
	graph->sink = NULL;
	graph->vertex_count = 0;
	graph->edge_count = 0;
	return (graph);
}
