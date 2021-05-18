#include "lem_in.h"

/*
 *	Print the amount of ants to be sent down each path.
 */

void	lem_print_ants_per_path(int *ants_per_path, t_parray *paths)
{
	size_t		i;
	t_parray	*max_flow_paths;

	max_flow_paths = parr_get_last(paths);
	i = 0;
	while (i < max_flow_paths->len)
	{
		print("path %d: %d ants\n", (int)i, ants_per_path[i]);
		i++;
	}
}
