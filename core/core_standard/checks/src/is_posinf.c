/******************************************************************************
 *
 * \authors Satu Koskinen
 *
 * \brief Returns 1 if `n` is positive infinity.
 *
 *****************************************************************************/

#include "../../../inc/core.h"

int	is_posinf(double n)
{
	if (n == 1.0 / 0.0)
		return (CR_TRUE);
	return (CR_FALSE);
}
