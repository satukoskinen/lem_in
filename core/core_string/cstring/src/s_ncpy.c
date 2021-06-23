/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_ncpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 01:29:53 by jkoskela          #+#    #+#             */
/*   Updated: 2021/05/19 04:38:35 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cstr.h"

char	*s_ncpy(char *dst, const char *src, t_uint64 n)
{
	t_uint64	i;

	i = 0;
	while (src[i] && i < n)
	{
		dst[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}

/*
**  ----------------------------------------------------------------------------
**
**	S_ncpy
**
**	String copy (n); copies `n` characters from`src` to `dst`. Destination
**	string must be able to hold the contents of `src`.
**
**  ----------------------------------------------------------------------------
*/
