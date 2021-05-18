#include "lem_in.h"

/*
 *	Calculate the cost (in rounds) of each path determined by its length
 *	and by how many ants will be sent down that path. The maximum cost
 *	determines the total cost in rounds for the set of paths.
 */

static size_t	get_path_cost(t_parray *paths, int *ants_per_path)
{
	size_t		max_path_cost;
	size_t		path_cost;
	size_t		i;
	t_parray	*path;

	max_path_cost = 0;
	i = 0;
	while (i < paths->len)
	{
		path = parr_get(paths, i);
		path_cost = path->len + (size_t)ants_per_path[i] - 1;
		if (path_cost > max_path_cost)
			max_path_cost = path_cost;
		i++;
	}
	return (max_path_cost);
}

/*
 *	Divide the remaining ants evenly over all the paths.
 */

static void	add_remaining_ants(
	t_parray *paths,
	int *ants_per_path,
	size_t ants)
{
	size_t	i;

	while (ants > 0)
	{
		i = 0;
		while (i < paths->len && ants > 0)
		{
			ants_per_path[i] = ants_per_path[i] + 1;
			ants--;
			i++;
		}
	}
}

/*
 *	Optimize the amount of ants per path for the given set of paths,
 *	assuming that all paths will be used, by first adding to each path
 *	the difference between the path lengths of that path and the longest
 *	path (the last one in the array of paths). If there are still ants
 *	to be distributed after this, add them evenly for each path.
 */

static size_t	optimise_ants_per_path(
	t_parray *paths,
	int *ants_per_path,
	size_t ants)
{
	size_t		i;
	size_t		longest_path_len;
	size_t		len_diff;
	t_parray	*path;

	path = parr_get_last(paths);
	longest_path_len = path->len;
	i = 0;
	while (i < paths->len)
	{
		path = parr_get(paths, i);
		len_diff = longest_path_len - path->len;
		if (len_diff > ants)
			ants_per_path[i] = (int)ants;
		else
			ants_per_path[i] = (int)len_diff;
		ants -= (size_t)ants_per_path[i];
		i++;
	}
	if (ants > 0)
		add_remaining_ants(paths, ants_per_path, ants);
	return (get_path_cost(paths, ants_per_path));
}

/*
 *	Choose the optimal amount of ants per path for the path
 *	combination i to minimize the total path cost.
 */

static size_t	optimise_i_paths(t_parray *path_combinations,
	size_t i, int *ants_per_path, size_t ants)
{
	t_parray	*i_paths;
	size_t		path_cost;

	mem_set(ants_per_path, 0, sizeof(int) * path_combinations->len);
	i_paths = parr_get(path_combinations, i);
	path_cost = optimise_ants_per_path(i_paths, ants_per_path, ants);
	return (path_cost);
}

/*
 *	Optimise path use by choosing the combination of paths to use
 *	as well as the amount of ants to send down each path. This happens
 *	by iterating over all path combinations, starting with the smallest
 *	amount of paths (1), and choosing the optimal amount of ants for each
 *	path to minimize the total cost measured in rounds. Once the path cost
 *	stops decreasing, the minimum path cost has been found.
 */

void	lem_optimise_path_use(
	int		*ants_per_path,
	t_parray **paths_to_use,
	t_parray *path_combinations,
	size_t ants)
{
	size_t	max_flow;
	size_t	i;
	size_t	min_path_cost;
	size_t	path_cost;

	max_flow = path_combinations->len;
	min_path_cost = (size_t)-1;
	i = 0;
	while (i < max_flow)
	{
		path_cost = optimise_i_paths(path_combinations,
				i, ants_per_path, ants);
		if (path_cost >= min_path_cost)
			break ;
		min_path_cost = path_cost;
		i++;
	}
	*paths_to_use = parr_get(path_combinations, i - 1);
	optimise_i_paths(path_combinations, i - 1, ants_per_path, ants);
}
