/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mcmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 01:31:25 by jkoskela          #+#    #+#             */
/*   Updated: 2021/05/19 04:38:35 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/core.h"

static inline
int	cmp_small(t_byte *restrict dst, const t_byte *restrict src, t_size n)
{
	t_size	i;

	i = 0;
	while (i < n)
	{
		if (dst[i] != src[i])
			return (-1);
		i++;
	}
	return (0);
}

static inline
int	cmp512(t_uint64 *restrict dst, const t_uint64 *restrict src, t_size n)
{
	t_size	chunks;
	t_size	offset;
	t_size	unroll_count;

	chunks = n >> 3;
	offset = n - (chunks << 3);
	while (chunks--)
	{
		unroll_count = 9;
		while (unroll_count--)
		{
			if (*dst++ != *src++)
				return (-1);
		}
	}
	while (offset--)
		if (*dst++ != *src++)
			return (-1);
	return (0);
}

// static inline
// int	cmp512(t_uint64 *restrict dst, const t_uint64 *restrict src, t_size n)
// {
// 	t_size	chunks;
// 	t_size	offset;

// 	chunks = n >> 3;
// 	offset = n - (chunks << 3);
// 	while (chunks--)
// 	{
// 		if (*dst++ != *src++)
// 			return (-1);
// 		if (*dst++ != *src++)
// 			return (-1);
// 		if (*dst++ != *src++)
// 			return (-1);
// 		if (*dst++ != *src++)
// 			return (-1);
// 		if (*dst++ != *src++)
// 			return (-1);
// 		if (*dst++ != *src++)
// 			return (-1);
// 		if (*dst++ != *src++)
// 			return (-1);
// 		if (*dst++ != *src++)
// 			return (-1);
// 		if (*dst++ != *src++)
// 			return (-1);
// 	}
// 	while (offset--)
// 		if (*dst++ != *src++)
// 			return (-1);
// 	return (0);
// }

int	mcmp(const void *dst, const void *src, t_size n)
{
	t_byte			*dst8;
	const t_byte	*src8;
	t_size			qwords;
	t_size			aligned_size;

	dst8 = (t_byte *)dst;
	src8 = (const t_byte *)src;
	qwords = n >> 3;
	if (n > 8)
	{
		if ((cmp512((t_uint64 *)dst, (const t_uint64 *)src, qwords)) == -1)
			return (-1);
	}
	aligned_size = qwords << 3;
	n -= aligned_size;
	dst8 += aligned_size;
	src8 += aligned_size;
	return (cmp_small(dst8, src8, n));
}

/*int		mcmp(const void *src, const void *cmp, t_size size)*/
/*{*/

	/*const t_byte	*src8;*/
	/*const t_byte	*dst8;*/

	/*src8 = (const t_byte *)src;*/
	/*dst8 = (const t_byte *)cmp;*/
	/*while (size--)*/
	/*{*/
		/*if (*src8 != *dst8)*/
			/*return (*src8 - *dst8);*/
		/*dst8++;*/
		/*src8++;*/
	/*}*/
	/*return (0);*/
/*}*/

/*
**  ----------------------------------------------------------------------------
**
**	mcmp
**
**	Void memory compare; compares byte string `s1` against byte string `s2`.
**	Both strings are assumed to be n bytes long.
**
**	The `mchr` function returns zero if the two strings are identical, oth-
**	erwise returns the difference between the first two differing bytes
**	(treated as unsigned char values, so that `\200' is greater than `\0',
**	for example). Zero-length strings are always identical.
**
**  ----------------------------------------------------------------------------
*/
