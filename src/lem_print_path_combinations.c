#include "lem_in.h"

/*
 *	Print all path combinations found at each iteration
 *	of finding an augmenting flow in the max flow algorithm.
 */

t_ssize	lem_print_path_combinations(void *data, t_size i)
{
	t_parray	*path;

	path = data;
	print("\033[1;31mIteration %d:\033[0m %d paths found\n", (int)i, path->len);
	parr_iter(path, lem_print_path);
	return ((t_ssize)i);
}
