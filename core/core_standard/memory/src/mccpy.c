/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mccpy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 01:31:12 by jkoskela          #+#    #+#             */
/*   Updated: 2021/05/19 04:29:48 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/core.h"

void	*mccpy(void *dst, const void *src, int c, t_size n)
{
	t_byte	*dst8;
	t_byte	*src8;

	dst8 = (t_byte *)dst;
	src8 = (t_byte *)src;
	while (n--)
	{
		*dst8 = *src8;
		if (*src8 == (t_byte)c)
			return (dst8 + 1);
		dst8++;
		src8++;
	}
	return (NULL);
}

/*
**  ----------------------------------------------------------------------------
**
**	mccpy
**
**	Void memory copy (c); copies bytes from string src to string dst.  If
**	the character c (as converted to an t_byte) occurs in the string
**	src, the copy stops and a pointer to the byte after the copy of c in the
**	memory dst is returned.  Otherwise, n bytes are copied, and a NULL
**	pointer is returned.
**
**  ----------------------------------------------------------------------------
*/
