#include "../inc/string.h"

t_str	str_cpy(t_str dst, t_str src)
{
	if (dst.raw.size < src.len)
		raw_realloc(&dst.raw, src.len);
	raw_cpy(dst.raw, src.raw, src.len);
	dst.len = src.len;
	dst.raw.data[dst.len] = '\0';
	return (dst);
}
