///////////////////////////////////////////////////////////////////////////////
///
/// \authors Julius Koskela
///
/// \brief Find an index of an element.
///
/// Finds the index of an element passed as an argument from the array src.
///
/// \param src Source array.
/// \param key The element to be searched.
/// \return Index of the element or -1 on failure.
///
///////////////////////////////////////////////////////////////////////////////

#include "../inc/array.h"

t_ssize	arr_find(t_array *src, void *key)
{
	void	*value;
	t_size	i;

	i = 0;
	while (1)
	{
		if (i == src->len)
			break ;
		value = arr_get(src, i);
		if (mcmp(key, value, src->elem_size) == 0)
			return ((t_ssize)i);
		i++;
	}
	return (CR_EMPTY);
}
