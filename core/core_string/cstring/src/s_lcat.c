/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_lcat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 01:29:04 by jkoskela          #+#    #+#             */
/*   Updated: 2021/05/19 04:38:35 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cstr.h"

t_uint64	s_lcat(char *dst, const char *src, t_uint64 size)
{
	t_uint64	j;
	t_uint64	k;

	j = 0;
	k = 0;
	while (dst[j] && j < size)
		j++;
	while ((src[k]) && ((j + k + 1) < size))
	{
		dst[j + k] = src[k];
		k++;
	}
	if (j != size)
		dst[j + k] = '\0';
	return (j + s_len(src));
}

/*
**  ----------------------------------------------------------------------------
**
**	S_lcat
**
**	String catenate (l); Append `size` characters from `src` to the end of
**	`dst`. Destination string must be able to hold the results
**	(inc. NULL char).
**
**	Returns the size of the whole string after catenation.
**
**  ----------------------------------------------------------------------------
*/
