/******************************************************************************
 *
 * \authors Julius Koskela
 *
 * \brief Returns 1 if `c` is an uppercase letter.
 *
 *****************************************************************************/

#include "../../../inc/core.h"

int	is_upper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (CR_TRUE);
	return (CR_FALSE);
}
