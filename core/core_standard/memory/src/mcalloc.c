/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mcalloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 01:31:08 by jkoskela          #+#    #+#             */
/*   Updated: 2021/05/19 11:43:24 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/core.h"

void	*mcalloc(t_size nrawb, t_size size)
{
	void		*addr;

	addr = malloc(nrawb * size);
	if (addr)
		mset(addr, 0, nrawb * size);
	return (addr);
}

/*
**  ----------------------------------------------------------------------------
**
**	mcalloc
**
**	Void memory allocation (c); allocates and formats `nrawb` amount of
**	elements of size `size`.
**
**  ----------------------------------------------------------------------------
*/
