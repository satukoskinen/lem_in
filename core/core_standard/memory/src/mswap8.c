#include "../../../inc/core.h"

int	mswap8(t_uint8 *a, t_uint8 *b)
{
	if (a == b)
		return (0);
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
	return (1);
}
