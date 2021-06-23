/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_modf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 00:50:32 by jkoskela          #+#    #+#             */
/*   Updated: 2021/05/20 21:57:40 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/core.h"

typedef union u_double
{
	double			f;
	t_uint64		i;
}					t_double;

static double	aux(double x, double *iptr, t_double u, int e)
{
	if (e >= 52)
	{
		*iptr = x;
		if (e == 0x400 && u.i << 12 != 0)
			return (x);
		u.i &= 1ULL << 63;
		return (u.f);
	}
	if (e < 0)
	{
		u.i &= 1ULL << 63;
		*iptr = u.f;
		return (x);
	}
	return (0);
}

double	math_modf(double x, double *iptr)
{
	t_double	u;
	t_uint64	mask;
	int			e;
	double		ret;

	u = (t_double)x;
	e = (int)(u.i >> 52 & 0x7ff) - 0x3ff;
	ret = aux(x, iptr, u, e);
	if (ret)
		return (ret);
	mask = -1ULL >> 12 >> e;
	if ((u.i & mask) == 0)
	{
		*iptr = x;
		u.i &= 1ULL << 63;
		return (u.f);
	}
	u.i &= ~mask;
	*iptr = u.f;
	return (x - u.f);
}

/*
**  ----------------------------------------------------------------------------
**
**	math_modf
**
**	Convert double `x` into a decimal representation. Function returns mantissa
**	and integral part is stored in the previously allocated int pointer `iptr`.
**
**  ----------------------------------------------------------------------------
*/
