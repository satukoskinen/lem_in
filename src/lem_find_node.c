#include "lem_in.h"

static inline int	unroll(t_graph_node *cast, size_t id, size_t i)
{
	if (cast[i].id == id)
		return (1);
	if (cast[i + 1].id == id)
		return (1);
	if (cast[i + 2].id == id)
		return (1);
	if (cast[i + 3].id == id)
		return (1);
	if (cast[i + 4].id == id)
		return (1);
	if (cast[i + 5].id == id)
		return (1);
	if (cast[i + 6].id == id)
		return (1);
	if (cast[i + 7].id == id)
		return (1);
	return (0);
}

ssize_t	lem_find_node(t_array *dst, t_graph_node *node)
{
	size_t			i;
	t_graph_node	*cast;
	size_t	chunks;
	size_t	offset;

	cast = (t_graph_node *)dst->data;
	chunks = dst->len >> 3;
	offset = dst->len - (chunks << 3);
	i = 0;
	while (chunks--)
	{
		if (unroll(cast, node->id, i))
			return (1);
		i += 8;
	}
	while (offset--)
	{
		if (cast[i].id == node->id)
			return (1);
		i++;
	}
	return (0);
}
