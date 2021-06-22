/******************************************************************************
 * \brief Find all root nodes from a directed graph.
 * \param g Source graph.
 * \param roots An array to store the root nodes.
 * \return 1 on success 0 on failure.
 *****************************************************************************/

#include "../../../inc/core.h"

t_nodes	graph_find_roots(t_graph *g)
{
	t_nodes			roots;
	t_map_node		m_node;
	t_graph_node	*g_node;
	t_size			i;

	roots = parr_new(1);
	i = 0;
	while (i < g->count)
	{
		m_node = g->node[i];
		if (!map_null_node(&m_node))
		{
			g_node = (t_graph_node *)m_node.data;
			if (g_node->in.len == 0)
				parr_add_last(&roots, g_node);
		}
		i++;
	}
	return (roots);
}
