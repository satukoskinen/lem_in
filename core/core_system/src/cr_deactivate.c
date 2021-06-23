#include "../../inc/core.h"
#include "../inc/system_internal.h"

static void	free_trackers(void)
{
	t_size		i;
	t_tracker	*t;
	t_core		*core;

	core = cr_static();
	i = 0;
	while (i < core->allocs.len)
	{
		t = parr_get(&core->allocs, i);
		parr_free(&t->trace);
		free(t);
		i++;
	}
}

static void	free_errors(void)
{
	t_size	i;
	t_error	*t;
	t_core	*core;

	core = cr_static();
	i = 0;
	while (i < core->errors.len)
	{
		t = parr_get(&core->errors, i);
		parr_free(&t->trace);
		free(t->message);
		free(t);
		i++;
	}
}

void	cr_deactivate(void)
{
	t_core	*core;

	core = cr_static();
	if (core->track_errors == TRUE)
	{
		free_errors();
		parr_free(&core->errors);
	}
	if (core->track_allocs == TRUE)
	{
		free_trackers();
		parr_free(&core->allocs);
	}
}
