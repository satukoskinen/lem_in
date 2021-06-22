/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parr_parse.c                                       :+:      :+:    :+:*/
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/05/07 16:10:42 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/core.h"

t_ssize	parr_parse(t_parray *dst, t_parray *src,
		t_ssize (*f)(t_parray *, void *))
{
	t_size	i;
	void	*data;

	i = 0;
	if (parr_null(src) || parr_null(dst))
		return (CR_FAIL);
	while (i < src->len)
	{
		data = parr_get(src, i);
		if (!(f(dst, data)))
			return (i);
		i++;
	}
	return (i);
}

/*
**  ----------------------------------------------------------------------------
**
**	PARR_PARSE
**
**	iter array `src` so that for each rawber a parse function is executed
**	The parse function is user-defined and parses each rawber so that rersults
**	are added in `dst`.
**
**  ----------------------------------------------------------------------------
*/
