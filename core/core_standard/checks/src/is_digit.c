/******************************************************************************
 *
 * \authors Julius Koskela
 *
 * \brief Returns 1 if `c` is a digit character.
 *
 *****************************************************************************/

#include "../../../inc/core.h"

int	is_digit(int c)
{
	if ((c >= '0') && (c <= '9'))
		return (CR_TRUE);
	return (CR_FALSE);
}
