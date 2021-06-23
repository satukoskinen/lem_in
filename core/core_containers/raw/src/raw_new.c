#include "../../../inc/core.h"
#include "../../../core_system/inc/system_internal.h"

void	create_tracker(t_raw raw)
{
	t_tracker	*tracker;
	t_core		*core;

	core = cr_static();
	tracker = malloc(sizeof(t_tracker));
	if (core->track_allocs_backtrace == TRUE)
		tracker->trace = cr_stacktrace(2);
	else
		tracker->trace = (t_parray){NULL, 0, 0};
	tracker->raw = raw;
	parr_add_last(&core->allocs, tracker);
}

t_ssize	raw_setup(t_raw raw)
{
	t_core	*core;

	core = cr_static();
	if (!raw.data && CR_RECOVERY_POLICY == 0)
	{
		cr_error(&(t_file_pos){__FUNCTION__, __FILE__, __LINE__},
			"FAILED ALLOCATION");
		cr_log();
		exit(-1);
	}
	else if (!raw.data && CR_RECOVERY_POLICY == 1)
	{
		cr_error(&(t_file_pos){__FUNCTION__, __FILE__, __LINE__},
			"FAILED ALLOCATION");
		return (0);
	}
	if (core->track_allocs == 1)
		create_tracker(raw);
	return (1);
}

t_raw	raw_new(t_size bytes)
{
	t_raw	out;
	t_core	*core;

	core = cr_static();
	out.data = malloc(bytes);
	out.size = bytes;
	if (core->active == TRUE)
		if (!(raw_setup(out)))
			return ((t_raw){NULL, 0});
	return (out);
}
