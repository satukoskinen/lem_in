#include "lem_in.h"

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

int	*lem_optimise_path_use(
	t_parray **paths_to_use,
	t_parray *path_combinations,
	size_t ants)
{
	int		*ants_per_path;
	size_t	max_flow;
	size_t	i;
	size_t	min_path_cost;
	size_t	path_cost;

	max_flow = path_combinations->len;
	ants_per_path = (int *)malloc(sizeof(int) * max_flow);
	if (ants_per_path == NULL)
		return (NULL);
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
	return (ants_per_path);
}
