///////////////////////////////////////////////////////////////////////////////
///
/// \authors Julius Koskela
///
/// \brief Get a pointer to an element at a spesific index.
///
/// Does not copy the element, pointer points directly to the memory in the
/// array so be careful. Checks for out of bounds index.
///
/// \param src Source array.
///
/// \return Pointer to an element or NULL if no element is found.
///
///////////////////////////////////////////////////////////////////////////////

#include "../inc/array.h"

void	*arr_get(t_array *src, t_size index)
{
	t_byte	*raw_pos;

	if (index >= src->len || src->len == 0)
		return (NULL);
	raw_pos = src->raw.data;
	raw_pos += index * src->elem_size;
	return (raw_pos);
}
