#include "lem_in.h"

t_graph_edge	*lem_get_edge(t_graph_node *src, t_graph_node *dst)
{
	size_t			i;
	t_graph_edge	*edge;

	i = 0;
	while (i < src->out.len)
	{
		edge = arr_get(&src->out, i);
		if (edge->dst->id == dst->id)
			return (edge);
		i++;
	}
	return (NULL);
}
