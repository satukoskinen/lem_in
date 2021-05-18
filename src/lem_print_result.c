#include "lem_in.h"

void	lem_print_result(t_parray *input, t_parray *output)
{
	parr_iter(input, lem_print_string);
	print("\n");
	parr_iter(output, lem_print_string);
}
