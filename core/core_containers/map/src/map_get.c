/******************************************************************************
 * \authors
 * \brief
 * \param
 * \return
 *****************************************************************************/

#include "../../../inc/core.h"

void	*map_get(t_map *src, const char *key)
{
	t_uint64	hash_key;
	t_uint64	probe;
	t_size		i;

	if (!key)
		return (NULL);
	hash_key = src->hash(key);
	probe = 0;
	i = 0;
	while (i < src->count)
	{
		if (src->node[(hash_key + probe) % src->capacity].key
			&& s_cmp(src->node[(hash_key + probe) % src->capacity].key, key)
			== 0)
			return (src->node[(hash_key + probe) % src->capacity].data);
		probe = src->probe(i);
		i++;
	}
	return (NULL);
}
