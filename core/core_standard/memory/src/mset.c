/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mset.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 01:31:58 by jkoskela          #+#    #+#             */
/*   Updated: 2021/05/19 04:38:35 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/core.h"

static void	copy_words(t_uint64 *dst, const int c, t_size words)
{
	t_uint64	pages;
	t_uint64	offset;

	pages = words / 4;
	offset = words - pages * 4;
	while (pages--)
	{
		*dst++ = c;
		*dst++ = c;
		*dst++ = c;
		*dst++ = c;
	}
	while (offset--)
		*dst++ = c;
}

void	*mset(void *dst, int c, t_size size)
{
	t_byte		*dst8;
	t_size		offset;
	t_size		words;
	t_size		aligned_size;

	if (!dst)
		return (NULL);
	words = size / 8;
	aligned_size = words * 8;
	offset = size - aligned_size;
	copy_words(dst, c, words);
	if (offset)
	{
		dst8 = (t_byte *)dst;
		dst8 = &dst8[aligned_size];
		while (offset--)
			*dst8++ = c;
	}
	return (dst);
}

/*
**  ----------------------------------------------------------------------------
**
**	mset
**
**	Sets `size` bytes of memory pointed to by `dst` with value `c`.
**
**  ----------------------------------------------------------------------------
*/
