/******************************************************************************
 *
 * \authors Satu Koskinen
 *
 * \brief Returns 1 if `c` is a letter character.
 *
 *****************************************************************************/

#include "../../../inc/core.h"

int	is_alpha(int c)
{
	if (is_upper(c) || is_lower(c))
		return (CR_TRUE);
	return (CR_FALSE);
}
