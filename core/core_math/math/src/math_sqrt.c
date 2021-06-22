/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_sqrt.c                                         :+:      :+:    :+:*/
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 21:07:56 by jkoskela          #+#    #+#             */
/*   Updated: 2021/05/11 09:28:50 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/core.h"
#define CR_SQRTPREC 100

static double	p10(int num)
{
	double		rst;
	int			i;

	rst = 1.0;
	i = 0;
	if (num >= 0)
	{
		while (i < num)
		{
			rst *= 10.0;
			i++;
		}
	}
	else
	{
		while (i < (0 - num))
		{
			rst *= 0.1;
			i++;
		}
	}
	return (rst);
}

static void	whole(int i, double *z, double *j, double *rst)
{
	while (i > 0)
	{
		if (*z - ((2 * *rst) + (*j * p10(i))) * (*j * p10(i)) >= 0)
		{
			while (*z - ((2 * *rst) + (*j * p10(i))) * (*j * p10(i)) >= 0)
			{
				*j = *j + 1;
				if (*j >= 10)
					break ;
			}
			j--;
			*z -= ((2 * *rst) + (*j * p10(i))) * (*j * p10(i));
			*rst += *j * p10(i);
			*j = 1.0;
		}
		i--;
	}
}

static void	decimal(int i, double *z, double *j, double *rst)
{
	while (i >= 0 )
	{
		if (*z - ((2 * *rst) + (*j * p10(i))) * (*j * p10(i)) >= 0)
		{
			while (*z - ((2 * *rst) + (*j * p10(i))) * (*j * p10(i)) >= 0)
			{
				*j = *j + 1;
			}
			*j = *j - 1;
			*z -= ((2 * *rst) + (*j * p10(i))) * (*j * p10(i));
			*rst += *j * p10(i);
			*j = 1.0;
		}
		i--;
	}
}

double	math_sqrt(double n)
{
	double		z;
	double		rst;
	double		j;

	z = n;
	rst = 0.0;
	j = 1.0;
	whole(CR_SQRTPREC, &z, &j, &rst);
	decimal(0, &z, &j, &rst);
	return (rst);
}

/*
**  ----------------------------------------------------------------------------
**
**	math_sqrt
**
**	Calculate square root of n.
**
**	Method from: https://tinyurl.com/yy2ksnwu
**
**  ----------------------------------------------------------------------------
*/
