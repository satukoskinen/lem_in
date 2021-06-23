/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_pow.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 01:58:34 by jkoskela          #+#    #+#             */
/*   Updated: 2021/05/20 21:57:40 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/core.h"
#include "math.h"
#define POWPREC 0.00001

static double	math_pow__(double base, double exp, double high, double low)
{
	double		sqr;
	double		acc;
	double		mid;

	sqr = math_sqrt(base);
	acc = sqr;
	mid = high / 2;
	while (math_fabs(mid - exp) > POWPREC)
	{
		sqr = math_sqrt(sqr);
		if (mid <= exp)
		{
			low = mid;
			acc *= sqr;
		}
		else
		{
			high = mid;
			acc *= (1 / sqr);
		}
		mid = (low + high) / 2;
	}
	return (acc);
}

static double	math_pow_(double base, double exp, double high, double low)
{
	double		temp;

	if (exp >= 1)
	{
		temp = math_pow_(base, exp / 2, high, low);
		return (temp * temp);
	}
	else
		return (math_pow__(base, exp, high, low));
}

double	math_pow(double base, double exp)
{
	double		high;
	double		low;

	low = 0.0;
	high = 1.0;
	return (math_pow_(base, exp, high, low));
}

/*
**  ----------------------------------------------------------------------------
**
**	math_pow
**
**	Calculate `base` raised to the `exp`th power.
**
**  ----------------------------------------------------------------------------
*/
