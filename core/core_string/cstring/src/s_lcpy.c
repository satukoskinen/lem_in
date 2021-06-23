/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_lcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 01:29:10 by jkoskela          #+#    #+#             */
/*   Updated: 2021/05/19 04:38:35 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cstr.h"

t_uint64	s_lcpy(char *dst, const char *src, t_uint64 size)
{
	t_uint64	i;
	t_uint64	j;

	i = 0;
	j = 0;
	if (!dst)
		return (0);
	while (src[j])
		j++;
	if (!size)
		return (j);
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (j);
}

/*
**  ----------------------------------------------------------------------------
**
**	S_lcpy
**
**	String copy; copies `size` contents from `src` to `dst`. Destination string
**	must be able to hold the contents of `src`.
**
**	Returns the lenght of the copied string.
**
**  ----------------------------------------------------------------------------
*/
