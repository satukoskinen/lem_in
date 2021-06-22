#include "lem_in.h"

/*
 *	You guessed it. It prints a string.
 */

t_ssize	lem_print_string(void *data, t_size i)
{
	print("%s\n", (char *)data);
	return ((t_ssize)i);
}
