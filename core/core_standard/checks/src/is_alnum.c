/******************************************************************************
 *
 * \authors Satu Koskinen
 *
 * \brief Returns 1 if `c` is an alphanumeric character.
 *
 *****************************************************************************/

#include "../../../inc/core.h"

int	is_alnum(int c)
{
	if (is_alpha(c) || is_digit(c))
		return (CR_TRUE);
	return (CR_FALSE);
}
