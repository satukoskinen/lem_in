#include "../../../inc/core.h"

t_raw	raw_assign(void *src, t_size size)
{
	t_raw	raw;

	raw.data = src;
	raw.size = size;
	return (raw);
}
