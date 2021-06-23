/******************************************************************************
 *
 * \authors Julius Koskela
 *
 * \brief Returns 1 if `c` is an ascii character.
 *
 *****************************************************************************/

#include "../../../inc/core.h"

int	is_ascii(int c)
{
	if (c >= 0 && c <= 127)
		return (CR_TRUE);
	return (CR_FALSE);
}
