/******************************************************************************
 *
 * \authors Satu Koskinen
 *
 * \brief Returns 1 if `c` is a space.
 *
 *****************************************************************************/

#include "../../../inc/core.h"

int	is_space(int c)
{
	if (c == ' ')
		return (CR_TRUE);
	return (CR_FALSE);
}
