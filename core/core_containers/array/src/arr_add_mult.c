///////////////////////////////////////////////////////////////////////////////
///
/// \authors Julius Koskela
///
/// \brief Add multiple elements to a dynamic array.
///
/// Adds a variable amount of elements to a dynamic array passed as arguments.
/// Number of arguments have to be defined in the count variable.
///
/// \param dst Destination array.
/// \param count Number of elements passed as arguments.
/// \return 1 on success 0 on failure.
///
///////////////////////////////////////////////////////////////////////////////

#include "../inc/array.h"

t_ssize	arr_add_mult(t_array *dst, t_size count, ...)
{
	va_list	ap;

	va_start(ap, count);
	while (count--)
	{
		if (!(arr_add_last(dst, va_arg(ap, void *))))
			return (CR_FAIL);
	}
	va_end(ap);
	return ((t_ssize)dst->len);
}
