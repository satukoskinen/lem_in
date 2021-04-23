#include "lem_in.h"
#include "libft.h"
#include <stdlib.h>

static void	print_ants_per_path(int *ants_per_path, int *path_lengths,
size_t path_count, int ant_count)
{
	size_t	i;
	int		path_cost;

	i = 0;
	while (i < path_count)
	{
		path_cost = path_lengths[i] + ants_per_path[i] - 1;
		ft_printf("path %d: ants %d cost %d\n", i, ants_per_path[i], path_cost);
		i++;
	}
	ft_printf("ant_count %d\n", ant_count);
}

static int	*save_path_lengths(t_array *paths)
{
	int		*path_lengths;
	t_array	*path;
	size_t	i;

	path_lengths = (int *)malloc(sizeof(int) * array_size(paths));
	if (path_lengths == NULL)
		return (NULL);
	i = 0;
	while (i < array_size(paths))
	{
		path = *(t_array **)array_get(paths, i);
		path_lengths[i] = array_size(path) - 1;
		i++;
	}
	return (path_lengths);
}

static int	total_path_cost(int *ants_per_path, int *path_lengths,
size_t path_count)
{
	int		max_cost;
	int		path_i_cost;
	size_t	i;

	max_cost = 0;
	i = 0;
	while (i < path_count)
	{
		if (ants_per_path[i] == 0)
			path_i_cost = 0;
		else
			path_i_cost = path_lengths[i] + (ants_per_path[i] - 1);
		if (path_i_cost > max_cost)
			max_cost = path_i_cost;
		i++;
	}
	return (max_cost);
}

static size_t	get_smallest_cost_path(int *ants_per_path, int *path_lengths,
size_t path_count)
{
	size_t	i;
	size_t	smallest_cost_index;
	int		i_cost;
	int		smallest_cost;

	smallest_cost_index = 0;
	smallest_cost = path_lengths[0] + (ants_per_path[0] - 1);
	i = 0;
	while (i < path_count)
	{
		i_cost = path_lengths[i] + (ants_per_path[i] - 1);
		if (i_cost < smallest_cost)
		{
			smallest_cost_index = i;
			smallest_cost = i_cost;
		}
		i++;
	}
	return (smallest_cost_index);
}

static void	split_to_n_paths(int *ants_per_path, int *path_lengths,
int ant_count, size_t path_count)
{
	size_t	i;
	int		path_len_diff;

	i = 0;
	while (i < path_count)
	{
		path_len_diff = path_lengths[path_count - 1] - path_lengths[i];
		if (path_len_diff > ant_count)
			path_len_diff = ant_count;
		ants_per_path[i] = path_len_diff;
		ant_count -= path_len_diff;
		i++;
	}
	while (ant_count > 0)
	{
		i = get_smallest_cost_path(ants_per_path, path_lengths, path_count);
		ants_per_path[i] = ants_per_path[i] + 1;
		ant_count--;
	}
}

static int	split_to_n_cost(int paths_to_use, int *path_lengths,
size_t ant_count)
{
	int		*ants_per_path;
	int		path_cost;

	ants_per_path = (int *)malloc(sizeof(int) * paths_to_use);
	if (ants_per_path == NULL)
		return (-1);
	ft_memset(ants_per_path, 0, sizeof(int) * paths_to_use);
	split_to_n_paths(ants_per_path, path_lengths, ant_count, paths_to_use);
	if (PRINT_DEBUG)
		print_ants_per_path(ants_per_path, path_lengths, paths_to_use, ant_count);
	path_cost = total_path_cost(ants_per_path, path_lengths, paths_to_use);
	free(ants_per_path);
	return (path_cost);
}

static int	*optimize_ants_per_path(t_array *paths, int *path_lengths,
int ant_count)
{
	int		*ants_per_path;
	int		max_path_cost;
	int		n_path_cost;
	size_t	n;

	ants_per_path = (int *)malloc(sizeof(int) * array_size(paths));
	if (ants_per_path == NULL)
		return (NULL);
	ft_memset(ants_per_path, 0, sizeof(int) * array_size(paths));
	max_path_cost = split_to_n_cost(1, path_lengths, ant_count);
	n = 2;
	while (n < array_size(paths))
	{
		n_path_cost = split_to_n_cost(n, path_lengths, ant_count);
		if (max_path_cost < n_path_cost)
			break ;
		max_path_cost = n_path_cost;
		n++;
	}
	if (n == array_size(paths))
		n++;
	split_to_n_paths(ants_per_path, path_lengths, ant_count, n - 1);
	if (PRINT_DEBUG)
		print_ants_per_path(ants_per_path, path_lengths, n - 1, ant_count);
	return (ants_per_path);
}

int	*optimize_path_use(int ant_count, t_array *shortest_paths,
t_array *max_flow_paths, t_array **paths_to_use)
{
	int		*shortest_ants_per_path;
	int		*shortest_path_lengths;
	int		shortest_path_cost;
	int		*max_flow_ants_per_path;
	int		*max_flow_path_lengths;
	int		max_flow_cost;

	shortest_path_lengths = save_path_lengths(shortest_paths);
	if (shortest_path_lengths == NULL)
		return (NULL);
	shortest_ants_per_path = optimize_ants_per_path(shortest_paths, shortest_path_lengths, ant_count);
	if (shortest_ants_per_path == NULL)
		return (NULL);
	shortest_path_cost = total_path_cost(shortest_ants_per_path, shortest_path_lengths, array_size(shortest_paths));

	max_flow_path_lengths = save_path_lengths(max_flow_paths);
	if (max_flow_path_lengths == NULL)
		return (NULL);
	max_flow_ants_per_path = optimize_ants_per_path(max_flow_paths, max_flow_path_lengths, ant_count);
	if (max_flow_ants_per_path == NULL)
		return (NULL);
	max_flow_cost = total_path_cost(max_flow_ants_per_path, max_flow_path_lengths, array_size(max_flow_paths));
	if (max_flow_cost < shortest_path_cost)
	{
		*paths_to_use = max_flow_paths;
		return (max_flow_ants_per_path);
	}
	else
	{
		*paths_to_use = shortest_paths;
		return (shortest_ants_per_path);
	}
}

// void	optimize_ants_per_path_1(int *ants_per_path, int *path_lengths, int ant_count, size_t path_count)
// {
// 	int	shortest_path_cost;
// 	int	n;
// 	int	n_path_cost;
// 	size_t	i;
// 	size_t	j;
// 	int		path_len_diff;
// 	int		path_cost_diff;

// 	ft_memset(ants_per_path, 0, sizeof(int) * path_count);
// 	shortest_path_cost = path_lengths[0] + (ant_count - 1);
// 	n = 2;
// 	n_path_cost = split_to_n_cost(n, &path_lengths[1], ant_count);
// 	if (path_count == 2 || shortest_path_cost < n_path_cost)
// 	{
// 		ants_per_path[0] = ant_count;
// 		return ;
// 	}
// 	i = 1;
// 	while (i < path_count - 1 && ant_count > 0)
// 	{
// 		path_len_diff = path_lengths[i + 1] - path_lengths[i];
// 		if (path_len_diff > ant_count)
// 			path_len_diff = ant_count;
// 		ants_per_path[i] = path_len_diff;
// 		ant_count = ant_count - path_len_diff;
// 		j = 1;
// 		while (j < i && ant_count > 0)
// 		{
// 			path_cost_diff = path_lengths[i] - path_lengths[i - 1];
// 			if (path_cost_diff > ant_count)
// 				path_cost_diff = ant_count;
// 			ants_per_path[j] = ants_per_path[j] + path_cost_diff;
// 			ant_count = ant_count - path_cost_diff;
// 			j++;
// 		}
// 		i++;
// 	}
// 	while (ant_count > 0)
// 	{
// 		i = get_smallest_cost_path(&ants_per_path[1], &path_lengths[1], path_count - 1);
// 		ants_per_path[i] = ants_per_path[i] + 1;
// 		ant_count--;
// 	}
// }
