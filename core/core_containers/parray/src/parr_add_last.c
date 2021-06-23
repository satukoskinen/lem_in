/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parr_add_last.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/05/24 02:23:45 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/core.h"

t_ssize	parr_add_last(t_parray *arr, void *data)
{
	if (parr_null(arr))
		return (CR_FAIL);
	if (arr->len == arr->size)
	{
		if (!(parr_grow(arr, (arr->size + 1) * 2)))
			return (CR_FAIL);
	}
	arr->data[arr->len] = data;
	arr->len++;
	return (CR_SUCCESS);
}

/*
**  ----------------------------------------------------------------------------
**
**	PARR_ADD_LAST
**
**	Add a new rawber to the end of a dynamic string. If the string is not
**	sufficiently big a new memory area double the size of the previous one
**	is allocated. One extra rawber is added to the allocation for the case
**	that the string has size 0.
**
**  ----------------------------------------------------------------------------
*/
