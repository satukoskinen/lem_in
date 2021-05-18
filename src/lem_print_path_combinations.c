#include "lem_in.h"

/*
 *	Print all path combinations found at each iteration
 *	of finding an augmenting flow in the max flow algorithm.
 */

ssize_t	lem_print_path_combinations(void *data, size_t i)
{
	t_parray	*path;

	path = data;
	print("Iteration %d: %d paths found\n", (int)i, path->len);
	parr_iter(path, lem_print_path);
	return ((ssize_t)i);
}
