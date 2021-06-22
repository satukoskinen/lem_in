///////////////////////////////////////////////////////////////////////////////
///
/// \authors Julius Koskela
///
/// \brief Delete last element in a dynamic array.
///
/// If the element has pointers to allocated memory, those have to be handled
/// by the user.
///
/// \param src Source array.
/// \return 1 on success 0 on failure.
///
///////////////////////////////////////////////////////////////////////////////

#include "../inc/array.h"

t_ssize	arr_del_last(t_array *src)
{
	if (!(arr_del(src, src->len - 1)))
		return (CR_FAIL);
	return (CR_SUCCESS);
}
