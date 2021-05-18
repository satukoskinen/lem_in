#include "lem_in.h"

/*
 *	Free one path.
 */

static ssize_t	free_path(void *data, size_t i)
{
	t_parray	*path;

	path = data;
	parr_free(path);
	free(path);
	return ((ssize_t)i);
}

/*
 *	Free all paths in an array of paths.
 */

static ssize_t	free_paths(void *data, size_t i)
{
	t_parray	*paths;

	paths = data;
	parr_iter(paths, free_path);
	parr_free(paths);
	free(paths);
	return ((ssize_t)i);
}

/*
 *	Free path pointer arrays in all path combinations
 *	and then the path_combinations pointer array itself.
 */

void	lem_free_path_combinations(t_parray *path_combinations)
{
	parr_iter(path_combinations, free_paths);
	parr_free(path_combinations);
}
