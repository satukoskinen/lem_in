#include "lem_in.h"

void	lem_exit_error(char *msg)
{
	print_fd(2, "%s\n", msg);
	exit(1);
}
