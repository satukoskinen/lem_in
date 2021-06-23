/******************************************************************************
 *
 * \authors Julius Koskela
 *
 * \brief Delete a node from a map.
 *
 * \param src Destination map.
 * \param key Key identifier of the node.
 *
 * \return 1 on success 0 on failure.
 *
 *****************************************************************************/

#include "../../../inc/core.h"

t_ssize	map_del(t_map *src, const char *key)
{
	t_uint64	hash_key;
	t_uint64	probe;
	t_size		i;

	hash_key = src->hash(key);
	probe = 0;
	i = 0;
	while (i < src->count)
	{
		if (src->node[(hash_key + probe)
				% src->capacity].key
			&& s_cmp(src->node[(hash_key + probe)
					% src->capacity].key, key) == 0)
		{
			src->node[(hash_key + probe) % src->capacity]
				= (t_map_node){NULL, NULL};
			return (i);
		}
		probe = src->probe(i);
		i++;
	}
	return (0);
}
