#include "../inc/string.h"

static t_ssize	print_str(void *data, t_size i)
{
	t_str	*ptr;

	ptr = data;
	str_write(*ptr);
	if (!(write(1, "\n", 1)))
		return (CR_STOP);
	return (i);
}

void	page_print(t_page p)
{
	arr_iter(&p, print_str);
}
