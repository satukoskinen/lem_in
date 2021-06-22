#include "../inc/string.h"

void	str_free(t_str *str)
{
	raw_free(&str->raw);
	str->len = 0;
}
