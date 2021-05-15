#include "lem-in.h"

static ssize_t	free_path(void *data, size_t i)
{
	t_parray	*path;

	path = data;
	parr_free(path);
	return ((ssize_t)i);
}

static ssize_t	free_paths(void *data, size_t i)
{
	t_array	*paths;

	paths = data;
	arr_iter(paths, free_path);
	arr_free(paths);
	return ((ssize_t)i);
}

void	lem_free_path_combinations(t_array *path_combinations)
{
	arr_iter(path_combinations, free_paths);
	arr_free(path_combinations);
}
