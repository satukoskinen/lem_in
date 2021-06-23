/******************************************************************************
 *
 * \authors Satu Koskinen, Julius Koskela
 *
 * \brief Find edge between src and dst
 *
 * \param g Source graph.
 * \param src_key Key of the source node.
 * \param dst_key Key of the destimation node.
 *
 * \return Pointer to the edge found or NULL if no edge was found.
 *
 *****************************************************************************/

#include "../../../inc/core.h"

t_graph_edge	*graph_find_edge(t_graph *g,
				const char *src_key,
				const char *dst_key)
{
	t_graph_node	*node;
	t_graph_edge	*out;
	t_size			i;

	node = graph_find_node(g, src_key);
	i = 0;
	while (i < node->out.len)
	{
		out = parr_get(&node->out, i);
		if (s_cmp(out->v->key, dst_key) == 0)
			return (out);
		i++;
	}
	return (NULL);
}
