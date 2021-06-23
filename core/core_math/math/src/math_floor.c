/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_floor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 22:05:32 by jkoskela          #+#    #+#             */
/*   Updated: 2021/05/20 21:57:40 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/core.h"

static double	aux(double xcopy, t_int64 zeros, double n, double x)
{
	while (xcopy > n * 10)
	{
		n *= 10;
		++zeros;
	}
	while (zeros != -1)
	{
		xcopy -= n;
		if (xcopy < 0)
		{
			xcopy += n;
			n /= 10;
			--zeros;
		}
	}
	if (x < 0)
	{
		if (xcopy == 0)
			return (x);
		else
			return (x - (1 - xcopy));
	}
	else
		return (x - xcopy);
}

double	math_floor(double x)
{
	double		xcopy;
	t_int64		zeros;
	double		n;

	if (x < 0)
		xcopy = x * -1;
	else
		xcopy = x;
	zeros = 0;
	n = 1;
	return (aux(xcopy, zeros, n, x));
}

/*
**  ----------------------------------------------------------------------------
**
**	math__floor
**
**	Floor function maps to the least integer less than or equal to.
**
**  ----------------------------------------------------------------------------
*/
