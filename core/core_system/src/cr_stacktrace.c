#include "../../inc/core.h"
#include "../inc/system_internal.h"

t_parray	cr_stacktrace(t_size offset)
{
	t_parray	trace;
	char		**strings;
	t_size		size;
	void		*array[CR_STACK_TRACE_MAX];
	t_size		i;

	trace = parr_new(1);
	offset++;
	size = backtrace(array, CR_STACK_TRACE_MAX);
	strings = backtrace_symbols(array, size);
	i = offset + 1;
	while (i < size)
	{
		parr_add_last(&trace, strings[i]);
		i++;
	}
	free(strings);
	return (trace);
}
