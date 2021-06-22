#include "../../../inc/core.h"
#include "../../../core_system/inc/system_internal.h"

static t_ssize	deactivate_tracker(t_raw *raw)
{
	t_tracker	*tracker;
	t_size		i;
	t_core		*core;

	core = cr_static();
	i = 0;
	while (i < core->allocs.len)
	{
		tracker = parr_get(&core->allocs, i);
		if (tracker->raw.data == raw->data)
		{
			parr_del(&core->allocs, i);
			parr_free(&tracker->trace);
			free(tracker);
			return (TRUE);
		}
		i++;
	}
	return (FALSE);
}

void	raw_free(t_raw *raw)
{
	t_core	*core;

	core = cr_static();
	if (core->active && core->track_allocs)
		deactivate_tracker(raw);
	free(raw->data);
	raw->data = NULL;
	raw->size = 0;
}
