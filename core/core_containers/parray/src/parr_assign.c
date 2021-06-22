/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parr_assign.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/05/20 21:57:40 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/core.h"

t_ssize	parr_assign(t_parray *arr, void **src, t_size size)
{
	t_size	i;

	i = 0;
	if (parr_null(arr) || !src || size < 1)
		return (CR_FAIL);
	while (i < size)
	{
		if (!(parr_add_last(arr, src[i])))
			return (CR_FAIL);
		i++;
	}
	return (arr->size);
}

/*
**  ----------------------------------------------------------------------------
**
**	PARR_ASSIGN
**
**	Assign an array of pointer of known size to a dynamic array.
**
**  ----------------------------------------------------------------------------
*/
