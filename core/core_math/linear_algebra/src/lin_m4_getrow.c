/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lin_m4_getrow.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 00:30:42 by jkoskela          #+#    #+#             */
/*   Updated: 2021/04/24 21:39:30 by julius           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/core.h"

t_vec4	lin_m4_getrow(t_mat4 *src, t_uint8 row)
{
	t_vec4	out;

	out.v[0] = src->m[(row * 4)];
	out.v[1] = src->m[(row * 4) + 1];
	out.v[2] = src->m[(row * 4) + 2];
	out.v[3] = src->m[(row * 4) + 3];
	return (out);
}
