#include "../inc/string.h"

static t_ssize	free_str(void *data, t_size i)
{
	str_free(data);
	return (i);
}

void	page_free(t_page *p)
{
	arr_iter(p, free_str);
	arr_free(p);
}
