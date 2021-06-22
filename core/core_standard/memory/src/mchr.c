/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 01:31:19 by jkoskela          #+#    #+#             */
/*   Updated: 2021/05/19 04:25:36 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/core.h"

void	*mchr(const void *s, int c, t_size n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned const char *)s)[i] == (unsigned char)c)
			return ((void *)&((unsigned const char *)s)[i]);
		i++;
	}
	return (NULL);
}

/*
**  ----------------------------------------------------------------------------
**
**	mchr
**
**	Void memory search; function locates the first occurrence of `c`
**	(converted to an unsigned char) in string `s`.
**
**	The `mchr` function returns a pointer to the byte located, or NULL if
**	no such byte exists within `n` bytes.
**
**  ----------------------------------------------------------------------------
*/
