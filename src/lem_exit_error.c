#include "lem_in.h"

/*
 *	Print an error message to stderr and exit with exit code 1.
 */

void	lem_exit_error(char *msg)
{
	print_fd(2, "%s\n", msg);
	exit(1);
}
