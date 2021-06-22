/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_sin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 02:01:22 by jkoskela          #+#    #+#             */
/*   Updated: 2021/05/20 21:57:40 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/core.h"

double	math_sin(double x, t_int64 p)
{
	double		sum;
	t_int64		i;
	t_int64		j;

	sum = 0;
	x = x * (CR_PI / 180);
	i = 1;
	j = 1;
	while (i <= p)
	{
		if (i % 2 != 0)
			sum = sum + math_pow(x, j) / math_fac(j);
		else
			sum = sum - math_pow(x, j) / math_fac(j);
		i++;
		j = j + 2;
	}
	return (sum);
}

/*
**  ----------------------------------------------------------------------------
**
**	math_sin
**
**	Calculate sine of `x` with precision `p`.
**
**  ----------------------------------------------------------------------------
*/
