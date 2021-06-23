/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_cos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 02:01:22 by jkoskela          #+#    #+#             */
/*   Updated: 2021/05/20 21:57:40 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/core.h"

double	math_cos(double x, t_int64 p)
{
	return (math_sin(CR_PI / 2 - x, p));
}

/*
**  ----------------------------------------------------------------------------
**
**	math_cos
**	Calculate cosine of `x` with precision `p`.
**
**	Idea for optimization; save both sine and cosine when each is invoked.
**
**  ----------------------------------------------------------------------------
*/
