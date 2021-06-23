/******************************************************************************
 *
 * \authors Satu Koskinen
 *
 * \brief return 1 if `n` is negative infinity.
 *
 *****************************************************************************/

#include "../../../inc/core.h"

int	is_neginf(double n)
{
	if (n == -1.0 / 0.0)
		return (CR_TRUE);
	return (CR_FALSE);
}
