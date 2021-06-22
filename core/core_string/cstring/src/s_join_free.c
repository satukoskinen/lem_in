/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_join_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 01:05:39 by jkoskela          #+#    #+#             */
/*   Updated: 2021/05/24 02:23:45 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cstr.h"

char	*s_join_free(char *s1, char *s2, t_size flag)
{
	char	*out;

	out = s_join(s1, s2);
	if (out == NULL)
		return (NULL);
	if (flag == 1)
		s_del(&s1);
	else if (flag == 2)
		s_del(&s2);
	else if (flag == 3)
	{
		s_del(&s1);
		s_del(&s2);
	}
	return (out);
}

/*
**  ----------------------------------------------------------------------------
**
**	S_join_free
**
**	Join strings `s1` and `s2`. Frees the string referred to by `flag`.
**
**	0 = no free
**	1 = `s1` is freed
**	2 = `s2` is freed
**	3 = both strings are freed
**
**	Returns a memory allocated output `out`.
**
**  ----------------------------------------------------------------------------
*/
