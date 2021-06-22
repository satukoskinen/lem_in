/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/05/19 04:25:36 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/core.h"

t_parray	parr_new(t_size size)
{
	t_parray	out;

	out.size = size;
	out.len = 0;
	out.data = (void **)malloc(sizeof(void *) * size);
	if (!out.data)
	{
		print("Allocation failed in function: map!\n");
		return ((t_parray){NULL, 0, 0});
	}
	return (out);
}

/*
**  ----------------------------------------------------------------------------
**
**	Parr
**
**	Allocate a new dynamic array. You can pass any starting size and resizing
**	will be hanled automatically. A better initial size approximation leads to
**	fewer resizes.
**
**  ----------------------------------------------------------------------------
*/
