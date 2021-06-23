#include "../inc/string.h"

t_str	page_get(t_page *src, t_size i)
{
	t_str	*ptr;

	ptr = arr_get(src, i);
	return (*ptr);
}
