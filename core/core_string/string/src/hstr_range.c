#include "../inc/string.h"

t_hstr	hstr_range(t_str src, t_size s, t_size t)
{
	t_raw	raw;

	raw = raw_assign(src.raw.data, src.raw.size);
	return (hraw_range(raw, s, t));
}
