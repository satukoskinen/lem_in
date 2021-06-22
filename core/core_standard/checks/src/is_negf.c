/******************************************************************************
 *
 * \authors Satu Koskinen
 *
 * \brief Return 1 if `n` is negative.
 *
 *****************************************************************************/

#include "../../../inc/core.h"

int	is_negf(double n)
{
	t_uint64	double_as_int;
	t_byte		sign;

	mcpy_safe(&double_as_int, &n, sizeof(n));
	sign = (t_byte)(double_as_int >> 63);
	if (sign == 0)
		return (CR_FALSE);
	return (CR_TRUE);
}
