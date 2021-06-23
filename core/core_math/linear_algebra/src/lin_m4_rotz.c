/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lin_m4_rotz.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 00:30:42 by jkoskela          #+#    #+#             */
/*   Updated: 2021/04/24 21:39:52 by julius           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/core.h"

t_mat4	lin_m4_rotz(double angle)
{
	t_mat4	out;
	double	rad;

	rad = angle * (CR_PI / 180);
	out = lin_m4_id();
	out.m[0] = cos(rad);
	out.m[1] = -sin(rad);
	out.m[4] = sin(rad);
	out.m[5] = cos(rad);
	return (out);
}
