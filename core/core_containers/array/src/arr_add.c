///////////////////////////////////////////////////////////////////////////////
///
/// \authors Julius Koskela
///
/// \brief Add element to a specific index in a dynamic dstay.
///
/// Add an element to an index passed as an argument. If index is out of bounds
/// returns 0.
///
/// \param dst Destination array.
/// \param elem Element to be added.
/// \param index Index where element will be added.
/// \return 1 on success 0 on failure.
///
///////////////////////////////////////////////////////////////////////////////

#include "../inc/array.h"

t_ssize	arr_add(t_array *dst, void *elem, t_size index)
{
	t_byte	*raw_pos;
	t_byte	*raw_tmp;

	if (index > dst->len)
		return (CR_FAIL);
	if (dst->len == (dst->raw.size / dst->elem_size) - 1)
		raw_realloc(&dst->raw, dst->raw.size * 2);
	raw_pos = dst->raw.data;
	raw_pos += index * dst->elem_size;
	raw_tmp = dst->raw.data;
	raw_tmp += (index + 1) * dst->elem_size;
	mmove(raw_tmp, raw_pos, dst->elem_size * (dst->len - index));
	mcpy(raw_pos, elem, dst->elem_size);
	dst->len++;
	return (CR_SUCCESS);
}
