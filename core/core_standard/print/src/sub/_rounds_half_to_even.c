/******************************************************************************
 *
 * \authors Satu Koskinen
 *
 * \brief
 *
 *****************************************************************************/

#include "../../../inc/core.h"
#include "../inc/print_internal.h"

static int	has_exact_fraction(double nbr, int precision, double div)
{
	double		int_part;
	double		frac_part;
	t_uint64	integral_frac;

	frac_part = _modf(_fabs(nbr), &int_part);
	integral_frac = (t_uint64)(frac_part * div * 10);
	if (integral_frac % _uintmax_pow(5, precision + 1) == 0)
		return (1);
	else
		return (0);
}

int	_rounds_half_to_even(double nbr, int precision)
{
	double	div;

	div = _dpow(10.0, precision);
	if (_fabs(nbr * div) - (t_uint64)_fabs(nbr * div) != 0.5)
		return (0);
	if (has_exact_fraction(nbr, precision, div))
		return (1);
	else
		return (0);
}
