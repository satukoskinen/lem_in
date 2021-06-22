/******************************************************************************
 *
 * \authors Satu Koskinen
 *
 * \brief
 *
 *****************************************************************************/

#include "../../../inc/core.h"
#include "../inc/print_internal.h"

static double	get_sign(unsigned long long double_as_int)
{
	unsigned char	sign;

	sign = (unsigned char)(double_as_int >> 63);
	if (sign == 1)
		return (-1.0);
	else
		return (1.0);
}

double	_modf(double value, double *iptr)
{
	unsigned long long	double_as_int;
	int					exponent;
	unsigned long long	significand;
	double				sign;

	*iptr = value;
	if (value == 0.0 || value == -0.0 || is_nan(value))
		return (value);
	else if (is_posinf(value))
		return (0.0);
	else if (is_neginf(value))
		return (-0.0);
	mcpy_safe(&double_as_int, &value, sizeof(value));
	sign = get_sign(double_as_int);
	exponent = (short)(double_as_int >> 52 & 0x7FF) - 1023;
	significand = (double_as_int & 0x0000FFFFFFFFFFFFFULL) | (1ULL << 52);
	if (exponent < 0)
		*iptr = sign * 0.0;
	else if (exponent > 52)
		*iptr = value;
	else
		*iptr = (double)sign * (double)(significand >> (52 - exponent));
	return (value - *iptr);
}
