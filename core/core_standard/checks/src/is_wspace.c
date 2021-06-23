/******************************************************************************
 *
 * \authors Julius Koskela
 *
 * \brief Returns 1 if `c` is a whitespace character.
 *
 *****************************************************************************/

#include "../../../inc/core.h"

int	is_wspace(char c)
{
	if (c == ' '
		|| c == '\n'
		|| c == '\t'
		|| c == '\v'
		|| c == '\f'
		|| c == '\r')
		return (CR_TRUE);
	return (CR_FALSE);
}
