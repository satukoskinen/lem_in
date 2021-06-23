#include "../../../inc/core.h"

int	mswap32(t_uint32 *a, t_uint32 *b)
{
	if (a == b)
		return (0);
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
	return (1);
}
