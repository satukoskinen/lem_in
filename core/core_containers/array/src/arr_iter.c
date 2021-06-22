///////////////////////////////////////////////////////////////////////////////
///
/// \authors Julius Koskela
///
/// \brief Iterate a dynamic array and apply f to each element.
///
/// An iterator function that takes a user defined function f as a parameter
/// and applies f to each element iterated. If f returns a
/// value < 1, iteration stops.
///
/// \param src Source array.
/// \param f A function to be applied to each iterated element.
///
/// \return Amount of elements iterated on success or 0 on failure.
///
///////////////////////////////////////////////////////////////////////////////

#include "../inc/array.h"

t_ssize	arr_iter(t_array *src,
		t_ssize (*f)(void *, t_size))
{
	t_size	i;
	void	*tmp;

	if (arr_null(src))
		return (CR_FAIL);
	i = 0;
	while (i < src->len)
	{
		tmp = arr_get(src, i);
		if ((f(tmp, i)) == CR_STOP)
			return ((t_ssize)i);
		i++;
	}
	return ((t_ssize)i);
}
