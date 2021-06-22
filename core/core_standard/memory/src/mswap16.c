#include "../../../inc/core.h"

int	mswap16(t_uint16 *a, t_uint16 *b)
{
	if (a == b)
		return (0);
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
	return (1);
}
