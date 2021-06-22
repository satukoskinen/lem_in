#include "../../inc/core.h"
#include "../inc/system_internal.h"

t_core	*cr_static(void)
{
	static t_core	core;

	return (&core);
}
