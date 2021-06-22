/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parr_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/05/23 21:26:54 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/core.h"

t_ssize	parr_split(t_parray *dst, t_parray *src)
{
	t_size	o_size;
	t_size	i;

	if (parr_null(dst) || parr_null(src))
		return (CR_FAIL);
	o_size = src->len;
	i = 0;
	while (i <= o_size / 2)
	{
		if (!(parr_add_last(dst, parr_take_last(src))))
			return (CR_FAIL);
		i++;
	}
	return (dst->len);
}

/*
**  ----------------------------------------------------------------------------
**
**	PARR_SPLIT
**
**	Split array `src` by putting half of it's rawbers into `src`.
**
**  ----------------------------------------------------------------------------
*/
