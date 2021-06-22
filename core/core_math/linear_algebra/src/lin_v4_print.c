/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lin_v4_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 00:30:42 by jkoskela          #+#    #+#             */
/*   Updated: 2021/05/20 21:57:40 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/core.h"

t_ssize	lin_v4_print(void *elem, t_size i)
{
	t_vec4	*src;

	src = elem;
	print("[%zu] {%.2lf}{%.2lf}{%.2lf}{%.2lf}\n",
		i, src->v[0], src->v[1], src->v[2], src->v[3]);
	return (i);
}
