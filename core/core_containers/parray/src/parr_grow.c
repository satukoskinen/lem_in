/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parr_grow.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/05/23 18:02:45 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/core.h"

t_ssize	parr_grow(t_parray *arr, t_size new_size)
{
	t_parray	out;
	t_ssize		error;

	out = parr_new(new_size);
	if (parr_null(&out))
		return (CR_FAIL);
	out.len = arr->len;
	error = parr_copy(&out, arr);
	if (!error)
		return (CR_FAIL);
	parr_free(arr);
	*arr = out;
	return (out.size);
}

/*
**  ----------------------------------------------------------------------------
**
**	PARR_GROW
**
**	Increase the size of the array.
**
**  ----------------------------------------------------------------------------
*/
