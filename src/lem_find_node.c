#include "lem_in.h"

ssize_t	lem_find_node(t_array *dst, t_graph_node *node)
{
	size_t			i;
	t_graph_node	*cast;

	i = 0;
	cast = (t_graph_node *)dst->data;
	while (i < dst->len)
	{
		if (cast[i].id == node->id)
		{
			return (1);
		}
		i++;
	}
	return (0);
}
