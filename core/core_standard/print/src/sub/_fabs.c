/******************************************************************************
 *
 * \authors Satu Koskinen
 *
 * \brief
 *
 *****************************************************************************/

#include "../../../inc/core.h"
#include "../inc/print_internal.h"

long double	_fabsl(long double nbr)
{
	if (nbr < 0.0 || nbr == -0.0)
		return (-nbr);
	else
		return (nbr);
}

double	_fabs(double nbr)
{
	if (is_neg(nbr))
		return (-nbr);
	else
		return (nbr);
}
