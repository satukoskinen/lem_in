/******************************************************************************
 *
 * \authors Julius Koskela
 *
 * \brief Returns 1 if `c` is a lowercase letter.
 *
 *****************************************************************************/

#include "../../../inc/core.h"

int	is_lower(int c)
{
	if (c >= 'a' && c <= 'z')
		return (CR_TRUE);
	return (CR_FALSE);
}
