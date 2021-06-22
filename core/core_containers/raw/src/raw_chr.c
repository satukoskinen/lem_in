#include "../../../inc/core.h"

t_hraw	raw_chr(t_raw src, t_raw b)
{
	t_hraw	res;
	t_size	i;

	res.data = NULL;
	res.size = 0;
	i = 0;
	while (i < src.size)
	{
		if (mcmp(&src.data[i], b.data, b.size) == 0)
		{
			res = hraw_range(src, i, src.size);
			return (res);
		}
		i++;
	}
	return (res);
}
