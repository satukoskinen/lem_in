#include "lem_in.h"

/*
 *	Print the amount of ants to be sent down each path.
 */

void	lem_print_ants_per_path(int *ants_per_path, t_parray *paths)
{
	size_t	i;

	print("Using %d paths:\n", (int)paths->len);
	i = 0;
	while (i < paths->len)
	{
		print("path %d: %d ants\n", (int)i, ants_per_path[i]);
		i++;
	}
	print("\n");
}
