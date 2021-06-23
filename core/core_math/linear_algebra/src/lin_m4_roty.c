/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lin_m4_roty.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 00:30:42 by jkoskela          #+#    #+#             */
/*   Updated: 2021/04/24 21:40:04 by julius           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/core.h"

t_mat4	lin_m4_roty(double angle)
{
	t_mat4	out;
	double	rad;

	rad = angle * (CR_PI / 180);
	out = lin_m4_id();
	out.m[0] = cos(rad);
	out.m[2] = sin(rad);
	out.m[8] = -sin(rad);
	out.m[10] = cos(rad);
	return (out);
}
