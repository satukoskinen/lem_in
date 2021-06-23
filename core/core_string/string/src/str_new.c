#include "../inc/string.h"

t_str	str_new(t_size len)
{
	t_str	new;

	new.raw = raw_new(len + 1);
	new.len = len;
	new.raw.data[0] = '\0';
	return (new);
}
