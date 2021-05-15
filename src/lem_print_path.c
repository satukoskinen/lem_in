#include "lem-in.h"

ssize_t	lem_print_path(void *data, size_t i)
{
	print("Path %d:\n", (int)i);
	parr_iter((t_parray *)data, lem_print_node);
	return ((ssize_t)i);
}
