/******************************************************************************
 * \authors
 * \brief
 * \param
 * \return
 *****************************************************************************/

#include "../../../inc/core.h"

t_ssize	graph_cmp_nodes(const void *n1, const void *n2)
{
	t_graph_node	*n1c;
	t_graph_node	*n2c;

	n1c = (t_graph_node *)n1;
	n2c = (t_graph_node *)n2;
	if (s_cmp(n1c->key, n2c->key) == 0)
		return (1);
	return (0);
}
