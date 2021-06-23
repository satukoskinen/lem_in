/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parr_dup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/05/23 21:26:54 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/core.h"

t_ssize	parr_dup(t_parray *dst, t_parray *src, t_size size)
{
	void	*elem;
	t_size	i;

	elem = NULL;
	i = 0;
	if (parr_null(src) || parr_null(dst))
		return (CR_FAIL);
	while (i < src->len)
	{
		elem = mcpy_safe(elem, parr_get(src, i), size);
		if (!(parr_add_last(dst, elem)))
			return (CR_FAIL);
		i++;
	}
	return (i);
}

/*
**  ----------------------------------------------------------------------------
**
**	PARR_DUP
**
**	Duplicate contents from `src` to `dst`. This method assumes that all
**	rawbers in the array are of equal size and that size is passed in bytes in
**	the parameter `size`.
**
**  ----------------------------------------------------------------------------
*/
