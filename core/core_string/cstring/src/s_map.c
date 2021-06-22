/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_map.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 01:29:29 by jkoskela          #+#    #+#             */
/*   Updated: 2021/05/24 02:23:45 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cstr.h"

char	*s_map(char const *s, char (*f)(char))
{
	unsigned int	n;
	char			*out;

	n = 0;
	out = (char *)malloc(sizeof(char) * (s_len(s)) + 1);
	if (out == NULL)
		return (NULL);
	while (s[n] != '\0')
	{
		out[n] = f(s[n]);
		n++;
	}
	out[n] = '\0';
	return (out);
}

/*
**  ----------------------------------------------------------------------------
**
**	S_map
**
**	String map; applies function `f` on all elements of string `out` and stores
**	the results in string `out`.
**
**	Returns a memory allocated output `out`.
**
**  ----------------------------------------------------------------------------
*/
