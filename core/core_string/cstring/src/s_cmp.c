/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_cmp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 01:28:12 by jkoskela          #+#    #+#             */
/*   Updated: 2021/05/09 02:09:52 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cstr.h"

int	s_cmp(const char *s1, const char *s2)
{
	unsigned int	i;

	i = 0;
	if (!s1 && !s2)
		return (0);
	if (!s1 || !s2)
		return (-1);
	while (s1[i] != '\0' && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/*
**  ----------------------------------------------------------------------------
**
**	S_cmp
**
**	String compare, lexicographically compares the null-terminated
**	strings `s1` and `s2`.
**
**	Returns 0 if strings are identical. Otherwise it returns the difference
**	(in integers) between the first non-matching characters in the strings.
**
**  ----------------------------------------------------------------------------
*/
