/******************************************************************************
 *
 * \authors Satu Koskinen
 *
 * \brief
 *
 *****************************************************************************/

#include "../../../inc/core.h"
#include "../inc/print_internal.h"

static double	round_half_to_even(double nbr, double div, t_size precision)
{
	double	tmp;
	double	int_part;
	double	frac_part;

	tmp = nbr;
	if (precision == 0)
	{
		tmp /= 10;
		precision = 1;
	}
	frac_part = _modf(tmp, &int_part);
	while (precision-- > 0)
		frac_part *= 10;
	if ((t_uint64)frac_part % 2 == 0 && nbr < 0.0)
		return (nbr + 0.5 / div);
	else if ((t_uint64)frac_part % 2 == 0 && nbr >= 0.0)
		return (nbr - 0.5 / div);
	else if (nbr < 0.0)
		return (nbr - 0.5 / div);
	else
		return (nbr + 0.5 / div);
}

long double	_round_double(double nbr, t_size precision)
{
	t_size		i;
	double		div;
	long double	long_nbr;

	i = 0;
	div = 1.0;
	long_nbr = nbr;
	while (i++ < precision)
		div *= 10;
	if (_rounds_half_to_even(nbr, (int)precision))
		long_nbr = round_half_to_even(nbr, div, precision);
	if (is_neg(nbr))
		long_nbr = (long_nbr - 0.5 / div);
	else
		long_nbr = (long_nbr + 0.5 / div);
	return (long_nbr);
}
