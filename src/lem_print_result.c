#include "lem_in.h"

/*
 *	Print the requited results on standard output:
 *	the received input and the rounds to move the ants
 *	from source to sink.
 */

void	lem_print_result(t_parray *input, t_parray *output)
{
	parr_iter(input, lem_print_string);
	print("\n");
	parr_iter(output, lem_print_string);
}
