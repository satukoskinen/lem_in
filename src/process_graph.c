#include "lem_in.h"
#include "libft.h"

int	process_graph(t_graph *graph, t_array **output)
{
	int		ret;
	char	*result;

	ret = 1;
//	ret = find_shortest_path(graph->source, graph->sink, output);
	ret = max_flow_edmonds_karp(graph->source, graph->sink, graph);
//	ft_printf("ret is %d\n", ret);
	result = ft_itoa(ret);
	array_add(output, &result);
	if (ret <= 0 && graph)
		return (ret);
	else
		return (1);
}
