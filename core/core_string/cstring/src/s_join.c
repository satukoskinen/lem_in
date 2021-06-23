/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_join.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 01:28:57 by jkoskela          #+#    #+#             */
/*   Updated: 2021/05/24 02:23:45 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cstr.h"

char	*s_join(char const *s1, char const *s2)
{
	char	*out;

	out = NULL;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		out = s_dup(s2);
	if (!s2)
		out = s_dup(s1);
	if (s1 && s2)
	{
		out = s_new(s_len(s1) + s_len(s2) + 1);
		out = s_cpy(out, s1);
		out = s_cat(out, (char *)s2);
	}
	return (out);
}

/*
**  ----------------------------------------------------------------------------
**
**	S_join
**
**	Join strings `s1` and `s2`.
**
**	Returns a memory allocated output `out`.
**
**  ----------------------------------------------------------------------------
*/
