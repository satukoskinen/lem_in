///////////////////////////////////////////////////////////////////////////////
///
/// \authors Julius Koskela
///
/// \brief Iterate a range in a dynamic array and apply f to each element.
///
/// An iterator function that takes a user defined function f as a parameter
/// and applies f to each element iterated. Range of iteration is defined
/// to be from the variables start to end passed as arguments. If f returns a
/// value < 1, iteration stops.
///
/// \param src Source array.
/// \param start Start index of the range to be iterated.
/// \param end End index of the range to be iterated.
/// \param f A function to be applied to each iterated element.
///
/// \return Amount of elements iterated on success or 0 on failure.
///
///////////////////////////////////////////////////////////////////////////////

#include "../inc/array.h"

t_ssize	arr_iter_range(t_array *src, t_size start, t_size end,
		t_ssize (*f)(void *, t_size))
{
	t_size	i;
	void	*tmp;

	i = start;
	if (arr_null(src)
		|| start > src->len
		|| end > src->len
		|| start < end)
		return (CR_FAIL);
	while (i < end)
	{
		tmp = arr_get(src, i);
		if (!(f(tmp, i)))
			return ((t_ssize)i);
		i++;
	}
	return ((t_ssize)i);
}
