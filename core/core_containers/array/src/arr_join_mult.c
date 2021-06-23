///////////////////////////////////////////////////////////////////////////////
///
/// \authors Julius Koskela
///
/// \brief Join multiple arrays.
///
/// \param
///
/// \return
///
///////////////////////////////////////////////////////////////////////////////

#include "../inc/array.h"

t_ssize	arr_join_mult(t_array *dst, t_size len, ...)
{
	va_list	ap;
	t_array	*tmp;

	va_start(ap, len);
	while (len--)
	{
		tmp = va_arg(ap, t_array *);
		if (arr_null(tmp))
			return (CR_FAIL);
		if (!(arr_join(dst, tmp)))
			return (CR_FAIL);
	}
	va_end(ap);
	return ((t_ssize)dst->len);
}
