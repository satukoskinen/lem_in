/******************************************************************************
 *
 * \authors Julius Koskela
 *
 * \brief Returns 1 if `c` is a numeric character.
 *
 *****************************************************************************/

#include "../../../inc/core.h"

int	is_numeric(int c)
{
	if (s_chr("0123456789+-.", c))
		return (CR_TRUE);
	return (CR_FALSE);
}
