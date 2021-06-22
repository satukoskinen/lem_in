/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parr_take.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 06:09:12 by jkoskela          #+#    #+#             */
/*   Updated: 2021/05/23 21:26:54 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/core.h"

void	*parr_take(t_parray *arr, t_size index)
{
	void	*out;

	if (index > arr->len || parr_null(arr))
		return (NULL);
	out = parr_get(arr, index);
	if (!(parr_del(arr, index)))
		return (NULL);
	return (out);
}

/*
**  ----------------------------------------------------------------------------
**
**	PARR_TAKE
**
**	Take a rawber from a dynamic array at `index`. Contrary to get, take also
**	removes the rawber from the array.
**
**  ----------------------------------------------------------------------------
*/
