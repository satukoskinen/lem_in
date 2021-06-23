#include "../inc/string.h"

t_page	page_new(t_size size)
{
	t_page	new;

	new = arr_new(size, sizeof(t_str));
	return (new);
}
