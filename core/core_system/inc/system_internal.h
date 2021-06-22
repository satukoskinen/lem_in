#ifndef SYSTEM_INTERNAL_H
# define SYSTEM_INTERNAL_H
# include "../../inc/core.h"

typedef struct s_core
{
	t_uint8		active : 1;
	t_uint8		track_errors : 1;
	t_uint8		track_errors_backtrace : 1;
	t_uint8		track_allocs : 1;
	t_uint8		track_allocs_backtrace : 1;
	t_parray	errors;
	t_parray	allocs;
}				t_core;

typedef struct s_tracker
{
	t_raw		raw;
	t_parray	trace;
}				t_tracker;

typedef struct s_error
{
	char		*message;
	t_parray	trace;
}				t_error;

t_core	*cr_static(void);

#endif
