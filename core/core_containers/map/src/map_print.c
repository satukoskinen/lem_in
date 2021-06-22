#include "../inc/map.h"
#include "../../../inc/core.h"

void	map_print(t_map *m)
{
	t_size	i;

	i = 0;
	while (i < m->capacity)
	{
		if (map_null_node(&m->node[i]))
			print("[EMPTY]\n");
		else
			print("%s\n", m->node[i].key);
		i++;
	}
}
