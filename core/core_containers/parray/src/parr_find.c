/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parr_find.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/05/20 21:57:40 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/core.h"

void	*parr_find(t_parray *src, void *key, void *(*f)(void *, void *))
{
	void	*data;
	t_size	i;

	i = 0;
	data = NULL;
	if (parr_null(src))
		return (CR_FAIL);
	while (1)
	{
		if (i == src->len)
			break ;
		data = parr_get(src, i);
		data = f(key, data);
		if (data)
			return (data);
		i++;
	}
	return (NULL);
}

/*
**  ----------------------------------------------------------------------------
**
**	PARR_FIND
**
**	Search from an array by passing a key and a selection function. In the
**	selection function user can put any logic and anything returned from
**	the selection function is returned as a void pointer.
**
**  ----------------------------------------------------------------------------
*/
