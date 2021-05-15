#include "lem_in.h"

ssize_t	lem_print_string(void *data, size_t i)
{
	print("%s\n", (char *)data);
	return ((ssize_t)i);
}
