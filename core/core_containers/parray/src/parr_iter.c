/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parr_iter.c                                        :+:      :+:    :+:*/
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/05/07 16:10:42 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/core.h"

t_ssize	parr_iter(t_parray *arr, t_ssize (*f)(void *, t_size))
{
	t_size	i;

	if (parr_null(arr))
		return (CR_FAIL);
	i = 0;
	while (i < arr->len)
	{
		if (f(arr->data[i], i) == CR_STOP)
			return (i);
		i++;
	}
	return (i);
}

/*
**  ----------------------------------------------------------------------------
**
**	PARR_iter
**
**	iter a dynamic array and execute a function passed by f on all
**	rawbers.
**
**  ----------------------------------------------------------------------------
*/
