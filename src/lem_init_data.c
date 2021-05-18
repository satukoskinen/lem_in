#include "lem_in.h"

/*
 *	Initialize variables in the lem struct.
 */

t_lem	lem_init_data(void)
{
	t_lem	lem;

	lem.graph = graph_new();
	lem.s_key = NULL;
	lem.t_key = NULL;
	lem.ant_count = 0;
	return (lem);
}
