/******************************************************************************
 *
 * \authors Julius Koskela
 *
 * \brief  Gives next power of two resize for a hash map.
 *
 * \param capacity Current capacity of the hash map.
 *
 * \return Value that can be used to grow the hash map.
 *
 *****************************************************************************/

#include "../../../inc/core.h"

static inline t_int64	m_ipow(t_int64 base, t_int64 exp)
{
	t_int64			tmp;
	t_int64			i;

	i = 0;
	tmp = base;
	if (base == 0 && exp == 0)
		return (1);
	else if (base == 0)
		return (0);
	else if (exp == 0)
		return (1);
	while (i < exp - 1)
	{
		tmp *= base;
		i++;
	}
	return (tmp);
}

t_uint64	map_resize_pow2(t_uint64 capacity)
{
	return (m_ipow(2, ceil(log(capacity) / log(2))));
}
