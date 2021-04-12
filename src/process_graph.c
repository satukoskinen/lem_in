#include "lem_in.h"

int	process_graph(t_graph *graph, t_array **output)
{
	int	ret;

	ret = find_shortest_path(graph->source, graph->sink, output);
	return (ret);
}