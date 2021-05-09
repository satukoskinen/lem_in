#include "lem_in.h"
#include "libft.h"

static size_t	get_path_cost(t_array *paths, int *ants_per_path)
{
	size_t		max_path_cost;
	size_t		path_cost;
	size_t		i;
	t_parray	*path;

	max_path_cost = 0;
	i = 0;
	while (i < paths->len)
	{
		path = arr_get(paths, i);
		path_cost = path->len + ants_per_path[i] - 1;
		if (path_cost > max_path_cost)
			max_path_cost = path_cost;
		i++;
	}
	return (max_path_cost);
}

static void	add_remaining_ants(
	t_array *paths,
	int *ants_per_path,
	size_t ant_count)
{
	size_t	i;

	while (ant_count > 0)
	{
		i = 0;
		while (i < paths->len && ant_count > 0)
		{
			ants_per_path[i] = ants_per_path[i] + 1;
			ant_count--;
			i++;
		}
	}
}

static size_t	optimise_ants_per_path(
	t_array *paths,
	int *ants_per_path,
	size_t ant_count)
{
	size_t		i;
	size_t		longest_path_len;
	size_t		len_diff;
	t_array		*path;

	path = arr_get_last(paths);
	longest_path_len = path->len;
	i = 0;
	while (i < paths->len)
	{
		path = arr_get(paths, i);
		len_diff = longest_path_len - path->len;
		if (len_diff > ant_count)
			ants_per_path[i] = ant_count;
		else
			ants_per_path[i] = len_diff;
		ant_count -= ants_per_path[i];
		i++;
	}
	if (ant_count > 0)
		add_remaining_ants(paths, ants_per_path, ant_count);
	return (get_path_cost(paths, ants_per_path));
}

static size_t	optimise_i_paths(t_array *path_combinations,
	size_t i, int *ants_per_path, size_t ant_count)
{
	t_array	*i_paths;
	size_t	path_cost;

	ft_memset(ants_per_path, 0, sizeof(int) * path_combinations->len);
	i_paths = arr_get(path_combinations, i);
	path_cost = optimise_ants_per_path(i_paths, ants_per_path, ant_count);
	return (path_cost);
}

int	*optimise_path_use(
	t_array **paths_to_use,
	t_array *path_combinations,
	size_t max_flow,
	int ant_count)
{
	int		*ants_per_path;
	size_t	i;
	size_t	min_path_cost;
	size_t	path_cost;

	ants_per_path = (int *)malloc(sizeof(int) * max_flow);
	if (ants_per_path == NULL)
		return (NULL);
	min_path_cost = -1;
	i = 0;
	while (i < max_flow)
	{
		path_cost = optimise_i_paths(path_combinations,
			i, ants_per_path, (size_t)ant_count);
		if (path_cost >= min_path_cost)
			break ;
		min_path_cost = path_cost;
		i++;
	}
	*paths_to_use = arr_get(path_combinations, i - 1);
	optimise_i_paths(path_combinations, i - 1, ants_per_path, ant_count);
	return (ants_per_path);
}

// int	*optimise_path_use_simple(size_t max_flow, int ant_count)
// {
// 	int		*ants_per_path;
// 	size_t	i;

// 	ants_per_path = (int *)malloc(sizeof(int) * max_flow);
// 	if (ants_per_path == NULL)
// 		return (NULL);
// 	ft_memset(ants_per_path, 0, sizeof(int) * max_flow);
// 	i = 0;
// 	while (i < max_flow)
// 	{
// 		if (ant_count == 0)
// 			break ;
// 		if (ant_count / (max_flow - i) == 0)
// 		{
// 			ants_per_path[i] = ants_per_path[i] + 1;
// 			ant_count--;
// 		}
// 		else
// 		{
// 			ants_per_path[i] = ant_count / (max_flow - i);
// 			ant_count -= ant_count / (max_flow - i);
// 		}
// 		i++;
// 	}
// 	return (ants_per_path);
// }
