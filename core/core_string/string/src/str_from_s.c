#include "../inc/string.h"

t_str	str_from_s(char *str)
{
	t_str	new;
	t_size	len;

	len = s_len(str);
	new = str_new(len);
	new.raw.data = mcpy(new.raw.data, str, len);
	new.raw.data[new.len] = '\0';
	return (new);
}
