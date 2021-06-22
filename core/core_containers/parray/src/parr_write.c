/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parr_write.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/05/20 21:57:40 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/core.h"

static
t_ssize	parr_write_string(t_parray *dst, t_parray *src)
{
	t_size	i;
	char	*tmp;

	i = 0;
	while (i < src->len)
	{
		tmp = src->data[i];
		parr_add_last(dst, s_dup(tmp));
		i++;
	}
	return (i);
}

t_ssize	parr_write(t_parray *dst, t_parray *src, t_ssize (*f)(void *, void *))
{
	t_size	i;
	void	*tmp;

	i = 0;
	if (f == CR_STRING)
		return (parr_write_string(dst, src));
	while (i < src->len)
	{
		tmp = NULL;
		if (f(tmp, parr_get(src, i)) == CR_STOP)
			return (i);
		parr_add_last(dst, tmp);
		i++;
	}
	return (i);
}

/*
**  ----------------------------------------------------------------------------
**
**	PARR_WRITE
**
**	Write contents from `src` to `dst`. Function `f` is a user specified
**	function which handles reading the data correctly, allocating space for it
**	and copying it. If a live pointer is returned from `f`, it is added
**	`dst`.
**
**  ----------------------------------------------------------------------------
*/
