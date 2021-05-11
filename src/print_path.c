#include "lem_in.h"

ssize_t	print_path(void *data, size_t i)
{
	print("Path %d:\n", (int)i);
	parr_iter((t_parray *)data, print_node);
	return ((ssize_t)i);
}
