///////////////////////////////////////////////////////////////////////////////
///
/// \authors Julius Koskela
///
/// \brief Search array key from src.
///
/// Searches for data in src that matches the whole data in key and returns the
/// index of the first matching element.
///
/// \param src Source array.
/// \param key Array data to be matched.
///
/// \return Index of the fisrt matching element on success, -1 on failure.
///
///////////////////////////////////////////////////////////////////////////////

#include "../inc/array.h"

t_ssize	arr_search(t_array *src, t_array *key)
{
	t_byte	*raw_key;
	t_byte	*raw_src;
	t_size	i;

	if (src->elem_size != key->elem_size)
		return (CR_FAIL);
	raw_src = (t_byte *)src->raw.data;
	raw_key = (t_byte *)key->raw.data;
	i = 0;
	while (i < src->len)
	{
		if (mcmp(&raw_src[key->elem_size * i],
				raw_key, key->len * key->elem_size) == 0)
			return ((t_ssize)i);
		i++;
	}
	return (CR_EMPTY);
}
