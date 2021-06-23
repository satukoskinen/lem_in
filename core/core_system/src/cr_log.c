#include "../../inc/core.h"
#include "../inc/system_internal.h"

static t_ssize	print_line(void *data, t_size i)
{
	char	*str;

	str = data;
	print("%s\n", str);
	return (i);
}

static t_ssize	print_tracker(void *data, t_size i)
{
	t_tracker	*tracker;

	tracker = data;
	if (tracker->raw.data)
	{
		print("rawptr: \033[1;31m%p\033[0m\n", tracker->raw.data);
		print("rawsize: \033[1;31m%lu\033[0m\n", tracker->raw.size);
	}
	if (!(parr_null(&tracker->trace)))
		parr_iter(&tracker->trace, print_line);
	print("\n");
	return (i);
}

static t_ssize	print_error(void *data, t_size i)
{
	t_error	*error;

	error = data;
	if (error->message)
		print("%s\n", error->message);
	if (!(parr_null(&error->trace)))
		parr_iter(&error->trace, print_line);
	print("\n");
	return (i);
}

void	cr_log(void)
{
	t_core	*core;

	core = cr_static();
	if (core->track_errors == TRUE)
		parr_iter(&core->errors, print_error);
	if (core->track_allocs == TRUE)
		parr_iter(&core->allocs, print_tracker);
}
