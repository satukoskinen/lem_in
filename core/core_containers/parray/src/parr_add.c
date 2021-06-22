/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parr_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/05/23 21:26:54 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/core.h"

t_ssize	parr_add(t_parray *arr, void *data, t_size index)
{
	t_parray	newarr;
	void		*tmp;
	t_size		i;

	if (index > arr->len)
		return (CR_FAIL);
	newarr = parr_new(arr->size);
	if (parr_null(&newarr))
		return (CR_FAIL);
	i = 0;
	while (i < index)
	{
		tmp = parr_take_first(arr);
		if (!(parr_add_last(&newarr, tmp)))
			return (CR_FAIL);
		i++;
	}
	parr_add_last(&newarr, data);
	parr_join(&newarr, 1, arr);
	parr_free(arr);
	*arr = newarr;
	return (CR_SUCCESS);
}

/*
**  ----------------------------------------------------------------------------
**
**	PARR_ADD
**
**	Add a new rawber to any index in an array. If index exceeds rawber
**	len, new rawber is added to the end of the array.
**
**  ----------------------------------------------------------------------------
*/
