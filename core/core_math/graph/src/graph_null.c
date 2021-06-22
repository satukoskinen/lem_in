/******************************************************************************
 * \brief Check if graph g is a null graph for error checking.
 * \return 1 on success 0 on failure.
 *****************************************************************************/

#include "../../../inc/core.h"

t_ssize	graph_null(t_graph *g)
{
	if (g->node->data == NULL)
		return (CR_SUCCESS);
	return (CR_FAIL);
}
