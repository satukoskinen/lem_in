#include "lem_in.h"

ssize_t	lem_print_path_combinations(void *data, size_t i)
{
	t_parray	*path;

	path = data;
	print("Iteration %d: %d paths found\n", (int)i, path->len);
	parr_iter(path, lem_print_path);
	return ((ssize_t)i);
}
