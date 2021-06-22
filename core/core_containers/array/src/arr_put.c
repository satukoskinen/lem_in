///////////////////////////////////////////////////////////////////////////////
///
/// \authors Julius Koskela
///
/// \brief Transfer elements from a standard array to a dynamic array.
///
/// \param dst Destination array.
/// \param src Source data.
///	\param len Source data element count
///
/// \return Total length of the array after operation.
///
///////////////////////////////////////////////////////////////////////////////

#include "../inc/array.h"

t_ssize	arr_put(t_array *dst, void *src, t_size len)
{
	t_size	i;
	t_byte	*raw;

	if (!src)
		return (CR_FAIL);
	raw = src;
	i = 0;
	while (i < len)
	{
		arr_add_last(dst, raw);
		raw += dst->elem_size;
		i++;
	}
	return ((t_ssize)dst->len);
}
