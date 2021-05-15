#include "lem-in.h"

void	lem_print_ants_per_path(int *ants_per_path, t_array *paths)
{
	size_t	i;
	t_array	*max_flow_paths;

	max_flow_paths = arr_get_last(paths);
	i = 0;
	while (i < max_flow_paths->len)
	{
		print("path %d: %d ants\n", (int)i, ants_per_path[i]);
		i++;
	}
}
