#include "../inc/map.h"
#include "../../../inc/core.h"

t_ssize	map_free(t_map *src)
{
	free(src->node);
	*src = (t_map){NULL, 0, 0, 0.0, NULL, NULL, NULL};
	return (CR_SUCCESS);
}
