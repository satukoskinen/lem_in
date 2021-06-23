/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_sub.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 01:30:41 by jkoskela          #+#    #+#             */
/*   Updated: 2021/05/24 02:23:45 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cstr.h"

char	*s_sub(char const *s, unsigned int start, t_uint64 len)
{
	char		*out;
	t_uint64	i;

	i = 0;
	if (!s)
		return (NULL);
	out = (char *)malloc(sizeof(char) * len + 1);
	if (!out)
		return (NULL);
	while (i < len)
	{
		out[i] = s[start + i];
		i++;
	}
	out[i] = '\0';
	return (out);
}

/*
**  ----------------------------------------------------------------------------
**
**	S_sub
**
**	Substring duplicate; Duplicate contents of `s` starting from index `start`
**	for lenght `len`.
**
**	Return a memory allocated output `out`.
**
**  ----------------------------------------------------------------------------
*/
