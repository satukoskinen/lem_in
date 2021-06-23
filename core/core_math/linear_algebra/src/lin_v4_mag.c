/*
 *  ----------------------------------------------------------------------------
 *
 *	Get the magintude of vector `v`.
 *
 *  ----------------------------------------------------------------------------
 */

#include "../../../inc/core.h"

double	lin_v4_mag(t_vec4 *src)
{
	double	out;

	out = sqrt(pow(src->v[0], 2)
			+ pow(src->v[1], 2)
			+ pow(src->v[2], 2)
			+ pow(src->v[3], 2));
	return (out);
}
