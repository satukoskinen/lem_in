/******************************************************************************
 * \authors
 * \brief
 * \param
 * \return
 *****************************************************************************/

#include "../../../inc/core.h"

t_ssize	graph_add_edge(
		t_graph *g,
		const char *u_key,
		const char *v_key,
		void *attr)
{
	t_graph_edge	*e;
	t_graph_node	*u;
	t_graph_node	*v;

	e = (t_graph_edge *)malloc(sizeof(t_graph_edge));
	if (!e)
		return (CR_FAIL);
	u = graph_find_node(g, u_key);
	v = graph_find_node(g, v_key);
	if (!u || !v)
	{
		print("Trying to connect an edge with a non-existing node!\n");
		free(e);
		return (-1);
	}
	e->u = u;
	e->v = v;
	e->valid = TRUE;
	e->attr = attr;
	parr_add_last(&u->out, e);
	parr_add_last(&v->in, e);
	return (CR_SUCCESS);
}
