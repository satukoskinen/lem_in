/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_copy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 03:47:58 by jkoskela          #+#    #+#             */
/*   Updated: 2021/05/19 04:25:36 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cstr.h"

char	*s_copy(char *str, t_size start, t_size end, t_size flag)
{
	char			*out;
	t_size			i;

	if (!str || start > end)
		return (NULL);
	out = NULL;
	if (end > 0)
		out = s_new(end - start);
	else
		s_new(s_len(str));
	i = 0;
	while (i < end - start && str[i + start])
	{
		out[i] = str[i + start];
		i++;
	}
	if (flag == 1)
		s_del(&str);
	return (out);
}

/*
**  ----------------------------------------------------------------------------
**
**	S_copy
**
**	A string copy with specified start and end points for copied area and a
**	flag to free the input string if necessary. If end is set to 0, the whole
**	string will be copied. Result string is allocated.
**
**  ----------------------------------------------------------------------------
*/
