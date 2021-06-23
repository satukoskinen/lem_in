/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_nequ.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 01:30:04 by jkoskela          #+#    #+#             */
/*   Updated: 2021/05/19 04:38:35 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cstr.h"

int	s_nequ(char const *s1, char const *s2, t_uint64 n)
{
	if (s1 == NULL || s2 == NULL)
		return (1);
	if (!s_ncmp(s1, s2, n))
		return (0);
	return (1);
}

/*
**  ----------------------------------------------------------------------------
**
**	S_nequ
**
**	String equal (n); compares `n` characters from strings `s1` and `s2`
**	and returns 1 if the strings are equal.
**
**  ----------------------------------------------------------------------------
*/
