/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mcpy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 01:31:35 by jkoskela          #+#    #+#             */
/*   Updated: 2021/06/12 21:44:55 by julius           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/core.h"

static inline
void	copy_small(t_byte *restrict dst, const t_byte *restrict src, t_size n)
{
	if (n >= 8)
	{
		*(t_uint64 *)dst = *(const t_uint64 * restrict)src;
		return ;
	}
	if (n >= 4)
	{
		*(t_uint32 *)dst = *(const t_uint32 * restrict)src;
		dst += 4;
		src += 4;
	}
	if (n & 2)
	{
		*(t_uint16 *)dst = *(const t_uint16 * restrict)src;
		dst += 2;
		src += 2;
	}
	if (n & 1)
		*dst = *src;
}

static inline
void	copy512(t_uint64 *restrict dst, const t_uint64 *restrict src, t_size n)
{
	t_size	chunks;
	t_size	offset;

	chunks = n >> 3;
	offset = n - (chunks << 3);
	while (chunks--)
	{
		*dst++ = *src++;
		*dst++ = *src++;
		*dst++ = *src++;
		*dst++ = *src++;
		*dst++ = *src++;
		*dst++ = *src++;
		*dst++ = *src++;
		*dst++ = *src++;
	}
	while (offset--)
		*dst++ = *src++;
}

void	*mcpy(void *dst, const void *restrict src, t_size n)
{
	t_byte			*dst8;
	const t_byte	*src8;
	t_size			qwords;
	t_size			aligned_size;

	dst8 = (t_byte *)dst;
	src8 = (const t_byte *)src;
	if (dst8 >= src8)
		return (mmove(dst, src, n));
	qwords = n >> 3;
	if (n >= 8)
		copy512((t_uint64 *)dst, (const t_uint64 *)src, qwords);
	aligned_size = qwords << 3;
	n -= aligned_size;
	dst8 += aligned_size;
	src8 += aligned_size;
	copy_small(dst8, src8, n);
	return (dst);
}

/*
**  ----------------------------------------------------------------------------
**
**	mcpy
**
**	Void memory copy; copies `n` bytes from memory area `src` to memory area
**	`dst`. If `dst` and `src` overlap, behavior is undefined. Applications in
**	which `dst` and `src` might overlap should use `mmove` instead.
**
**  ----------------------------------------------------------------------------
*/
