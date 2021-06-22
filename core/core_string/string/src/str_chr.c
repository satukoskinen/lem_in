#include "../inc/string.h"

t_hstr	str_chr(t_str src, char c)
{
	t_hraw	b;

	b = (t_hraw){(t_byte *)&c, 1};
	return (raw_chr(src.raw, b));
}
