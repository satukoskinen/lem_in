#include "../../../inc/core.h"

void	map_iter(t_map *src, t_ssize (*f)(void *, t_size))
{
	t_size	i;

	if (!src || !f)
		return ;
	i = 0;
	while (i < src->capacity)
	{
		if (!map_null_node(&src->node[i]))
			if (f(src->node[i].data, i) < 0)
				return ;
		i++;
	}
}
