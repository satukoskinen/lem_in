#include "../inc/string.h"

void	hstr_write(t_hstr str)
{
	if (!(write(1, str.data, str.size)))
		return ;
}
