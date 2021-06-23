///////////////////////////////////////////////////////////////////////////////
///
/// \authors Julius Koskela
///
/// \brief Free an array passed as an argument.
///
/// \param src Pointer to an array to be freed.
///
/// \return 1 on success.
///
///////////////////////////////////////////////////////////////////////////////

#include "../inc/array.h"

t_ssize	arr_free(t_array *src)
{
	raw_free(&src->raw);
	src->len = 0;
	src->elem_size = 0;
	return (CR_SUCCESS);
}
