///////////////////////////////////////////////////////////////////////////////
///
/// \authors Julius Koskela
///
/// \brief Sort array
///
/// \param src Source array
/// \param f Comparison method.
///
///////////////////////////////////////////////////////////////////////////////

#include "../inc/array.h"

static void	arr_sort_recurse(t_array *src,
	t_ssize low,
	t_ssize high,
	t_ssize (*f)(void *, void *))
{
	t_ssize	pivot;
	t_ssize	a;
	t_ssize	b;

	if (low < high)
	{
		pivot = low;
		a = low;
		b = high;
		while (a < b)
		{
			while (a <= high && f(arr_get(src, a), arr_get(src, pivot)) <= 0)
				a++;
			while (b >= low && f(arr_get(src, b), arr_get(src, pivot)) > 0)
				b--;
			if (a < b)
				mswap(arr_get(src, a), arr_get(src, b), src->elem_size);
		}
		mswap(arr_get(src, pivot), arr_get(src, b), src->elem_size);
		arr_sort_recurse(src, low, b - 1, f);
		arr_sort_recurse(src, b + 1, high, f);
	}
}

void	arr_sort(t_array *src, t_ssize (*f)(void *, void *))
{
	arr_sort_recurse(src, 0, src->len - 1, f);
}
