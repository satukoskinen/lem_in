#include "../../../inc/core.h"

t_raw	raw_cpy(t_raw dst, t_raw src, t_size size)
{
	if (size > dst.size)
		return ((t_raw){NULL, 0});
	mcpy(dst.data, src.data, src.size);
	return (dst);
}
