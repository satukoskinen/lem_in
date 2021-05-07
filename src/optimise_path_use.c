#include "lem_in.h"
#include "libft.h"

size_t	optimise_path_use(t_array *path_combinations, int **ants_per_path, int ant_count)
{
	t_array	*i_paths;
	int		max_flow;
	int		i;

	i_paths = arr_get(path_combinations, path_combinations->len - 1);
	max_flow = (int)i_paths->len;
	*ants_per_path = (int *)malloc(sizeof(int) * max_flow);
	if (*ants_per_path == NULL)
		return (0);
	ft_memset(*ants_per_path, 0, sizeof(int) * max_flow);
	i = 0;
	while (i < max_flow)
	{
		if (ant_count == 0)
			break ;
		if (ant_count / max_flow == 0)
		{
			*ants_per_path[i] += 1;
			ant_count--;
		}
		else
		{
			*ants_per_path[i] = ant_count / max_flow;
			ant_count -= ant_count / max_flow;
		}
		i++;
	}
	return ((size_t)i);
}
