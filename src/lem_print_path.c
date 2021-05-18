#include "lem_in.h"

/*
 *	Print nodes along a single path.
 */

ssize_t	lem_print_path(void *data, size_t i)
{
	print("Path %d: length %d\n", (int)i, ((t_parray *)data)->len);
	parr_iter((t_parray *)data, lem_print_node);
	print("\n");
	return ((ssize_t)i);
}
