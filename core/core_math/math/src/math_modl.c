/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_modl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 16:50:28 by jkoskela          #+#    #+#             */
/*   Updated: 2021/05/20 21:57:40 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/core.h"

typedef union u_ldshape
{
	long double		f;
	t_uint64		m;
	t_uint16		se;
}					t_ldshape;

typedef struct s_modl
{
	t_ldshape		u;
	int				e;
	int				s;
	long double		y;
	long double		absx;
	long double		toint;
}					t_modl;

long double	math_modl(long double x, long double *iptr)
{
	t_modl		vars;

	mzero(&vars, sizeof(t_modl));
	vars.u = (t_ldshape)x;
	vars.e = (vars.u.se & 0x7fff) - 0x3fff;
	vars.s = vars.u.se >> 15;
	if (vars.e >= LDBL_MANT_DIG - 1)
	{
		*iptr = x;
		if (vars.s)
			return (-0.0);
		else
			return (0.0);
	}
	if (vars.e < 0)
	{
		if (vars.s)
			*iptr = -0.0;
		else
			*iptr = 0.0;
		return (x);
	}
	return (-vars.y);
}

/*
**  ----------------------------------------------------------------------------
**
**	math_modl *UNSTESTED*
**
**	Convert long double `x` into a decimal representation. Function returns
**	mantissa and integral part is stored in the previously allocated int
**	pointer `iptr`.
**
**  ----------------------------------------------------------------------------
*/
