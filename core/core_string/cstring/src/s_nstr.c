/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_nstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 01:30:15 by jkoskela          #+#    #+#             */
/*   Updated: 2021/05/19 04:38:35 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cstr.h"

char	*s_nstr(const char *h, const char *n, t_uint64 len)
{
	t_uint64	i;
	t_uint64	j;

	i = 0;
	if (!s_len(n))
		return ((char *)h);
	while (i < len && h[i] != '\0')
	{
		j = 0;
		while (i + j < len && h[i + j] == n[j] && n[j] != '\0')
			j++;
		if (n[j] == '\0')
			return ((char *)h + i);
		i++;
	}
	return (NULL);
}

/*
**  ----------------------------------------------------------------------------
**
**	S_nstr
**
**	Locate substring (n); function locates the first occurrence of the
**	null-terminated string `n` in the string `h`, where not more than len
**	characters are searched.  Characters that appear after a `\0' character
**	are not searched.
**
**  ----------------------------------------------------------------------------
*/
