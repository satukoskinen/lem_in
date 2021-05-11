#include "lem_in.h"

ssize_t	print_path_combinations(void *data, size_t i)
{
	t_array	*path;

	path = data;
	print("Iteration %d: %d paths found\n", (int)i, path->len);
	arr_iter(path, print_path);
	return ((ssize_t)i);
}
