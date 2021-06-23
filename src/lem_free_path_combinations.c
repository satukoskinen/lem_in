#include "lem_in.h"

/*
 *	Free one path.
 */

static t_ssize	free_path(void *data, t_size i)
{
	t_parray	*path;

	path = data;
	parr_free(path);
	free(path);
	return ((t_ssize)i);
}

/*
 *	Free all paths in an array of paths.
 */

static t_ssize	free_paths(void *data, t_size i)
{
	t_parray	*paths;

	paths = data;
	parr_iter(paths, free_path);
	parr_free(paths);
	free(paths);
	return ((t_ssize)i);
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
