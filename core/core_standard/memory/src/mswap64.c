#include "../../../inc/core.h"

int	mswap64(t_uint64 *a, t_uint64 *b)
{
	if (a == b)
		return (0);
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
	return (1);
}
