///////////////////////////////////////////////////////////////////////////////
///
/// \authors Julius Koskela
///
/// \brief Copy elements from src to dst.
///
/// Checks that element sizes match between the arrays and copies from src to
/// dst. Overrides any data in dst.
///
/// \param dst Destination array.
/// \param src Source array.
/// \return 1 on success 0 on failure.
///
///////////////////////////////////////////////////////////////////////////////

#include "../inc/array.h"

t_ssize	arr_copy(t_array *dst, t_array *src)
{
	t_byte	*raw_start;

	if (arr_null(src))
		return (CR_FAIL);
	if (dst->raw.size <= src->len * src->elem_size)
		raw_realloc(&dst->raw, src->len * src->elem_size);
	raw_start = dst->raw.data;
	dst->raw.data = mcpy(
			raw_start,
			src->raw.data,
			src->len * src->elem_size);
	dst->len = src->len;
	return (CR_SUCCESS);
}
