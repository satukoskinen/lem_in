#include "lem_in.h"

int	map_contains_key(t_map *map, const char *key)
{
	if (map_get(map, key) == NULL)
		return (0);
	else
		return (1);
}
