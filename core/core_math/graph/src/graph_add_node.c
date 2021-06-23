/******************************************************************************
 * \brief Add a node n to graph g.
 *
 * New adjacency lists in and out are created for the node, after which the
 * node is added into the graph.
 *
 * \param g Source graph.
 * \param n Node to be added.
 * \return Total amount of nodes in the graph on success or -1 on failure.
 *****************************************************************************/

#include "../../../inc/core.h"

t_ssize	graph_add_node(t_graph *g, const char *key, void *attr)
{
	t_graph_node	*n;

	n = (t_graph_node *)malloc(sizeof(t_graph_node));
	if (!n)
	{
		print("Allocation failed in function: graph_add_node!\n");
		exit(-1);
	}
	n->key = key;
	n->valid = TRUE;
	n->in = parr_new(1);
	n->out = parr_new(1);
	n->attr = attr;
	if (!map_add(g, n, n->key))
	{
		parr_free(&n->in);
		parr_free(&n->out);
		free(n);
		return (CR_FAIL);
	}
	else
		return (CR_SUCCESS);
}
