/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lin_m4_getcol.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 00:30:42 by jkoskela          #+#    #+#             */
/*   Updated: 2021/04/24 21:39:42 by julius           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/core.h"

t_vec4	lin_m4_getcol(t_mat4 *src, t_uint8 col)
{
	t_vec4	out;

	out.v[0] = src->m[col];
	out.v[1] = src->m[4 + col];
	out.v[2] = src->m[8 + col];
	out.v[3] = src->m[12 + col];
	return (out);
}
