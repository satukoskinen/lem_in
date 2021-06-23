#include "../../../inc/core.h"

void	raw_print(t_raw src)
{
	t_size	i;

	i = 0;
	while (i < src.size - 1)
	{
		if (i % 8 == 0)
			print("\n");
		print("%#03x ", src.data[i]);
		i++;
	}
	if (i % 8 == 0)
		print("\n");
	print("%#03x ", src.data[i]);
}
