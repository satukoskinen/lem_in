#include "../../inc/core.h"
#include "../inc/system_internal.h"

void	cr_error(t_file_pos *err_pos, char *message)
{
	t_error	*error;
	t_core	*core;
	char	*fmt;

	fmt = "ERROR \033[1;31m%s\033[0m, \033[1;31m%s\033[0m, \033[1;31m%d\033[0m\n%s";
	core = cr_static();
	error = malloc(sizeof(t_error));
	error->message = format(fmt,
			err_pos->file,
			err_pos->func,
			err_pos->line,
			message);
	error->trace = cr_stacktrace(0);
	parr_add_last(&core->errors, error);
}
