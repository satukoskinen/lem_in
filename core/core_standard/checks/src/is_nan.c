/******************************************************************************
 *
 * \authors Satu Koskinen
 *
 * \brief Returns 1 if `n` is not a number.
 *
 *****************************************************************************/

#include "../../../inc/core.h"

int	is_nan(double n)
{
	if (n != n)
		return (CR_TRUE);
	return (CR_FALSE);
}
