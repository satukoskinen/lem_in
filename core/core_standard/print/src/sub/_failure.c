/******************************************************************************
 *
 * \authors Julius Koskela
 *
 * \brief
 *
 *****************************************************************************/

#include "../../../inc/core.h"
#include "../inc/print_internal.h"

int	_failure(t_data *specs, char **result)
{
	free(*result);
	specs->error = 1;
	return (-1);
}
