/******************************************************************************
 *
 * \authors Julius Koskela
 *
 * \brief  Probing function P(x) = (x^2 + x) / 2
 *
 * \param x Probing increment
 *
 * \return Value to be added to hash value to move to the next index
 *
 *****************************************************************************/

#include "../../../inc/core.h"

t_uint64	map_probe_quad_pow2(t_uint64 x)
{
	return ((pow(x, 2) + x) / 2);
}
