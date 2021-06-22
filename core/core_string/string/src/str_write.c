#include "../inc/string.h"

void	str_write(t_str str)
{
	if (!(write(1, str.raw.data, str.len)))
		return ;
}
