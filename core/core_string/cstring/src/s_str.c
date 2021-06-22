/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_str.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 01:30:37 by jkoskela          #+#    #+#             */
/*   Updated: 2021/05/11 09:05:38 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cstr.h"

char	*s_str(const char *h, const char *n)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (h[0] == '\0' && n[0] == '\0')
		return ((char *)h);
	while (h[i] != '\0')
	{
		j = 0;
		while (n[j] != '\0' && h[i + j] == n[j])
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
**	S_str
**
**	Locate substring; locates the first occurrence of the
**	null-terminated string `n` in the string `h`. Characters that appear
**	after a `\0' character are not searched.
**
**  ----------------------------------------------------------------------------
*/
