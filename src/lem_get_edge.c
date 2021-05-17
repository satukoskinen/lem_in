#include "lem_in.h"

t_graph_edge	*lem_get_edge(t_graph_node *src, t_graph_node *dst)
{
	size_t			i;
	t_graph_edge	*edge;

	i = 0;
	while (i < src->out.len)
	{
		edge = parr_get(&src->out, i);
		if (!s_cmp(edge->v->key, dst->key))
			return (edge);
		i++;
	}
	return (NULL);
}
