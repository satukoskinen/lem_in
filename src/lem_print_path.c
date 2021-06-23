#include "lem_in.h"

/*
 *	Print nodes along a single path.
 */

t_ssize	lem_print_path(void *data, t_size i)
{
	print("Path %d: length %d\n", (int)i, ((t_parray *)data)->len);
	parr_iter((t_parray *)data, lem_print_node);
	print("\n");
	return ((t_ssize)i);
}
