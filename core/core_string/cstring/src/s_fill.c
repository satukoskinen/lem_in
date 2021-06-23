/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_fill.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 21:20:36 by jkoskela          #+#    #+#             */
/*   Updated: 2021/05/19 04:25:36 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cstr.h"

char	*s_fill(char *data, t_size b_size, char *flags)
{
	char		*out;
	t_size		i;
	t_size		j;
	t_size		d_size;

	d_size = s_len(data);
	j = 0;
	if (b_size < d_size)
		return (data);
	if (s_chr(flags, '-'))
		i = 0;
	else
		i = b_size - d_size;
	if (s_chr(flags, '0'))
		out = s_newc(b_size, '0');
	else
		out = s_newc(b_size, ' ');
	while (data[j])
		out[i++] = data[j++];
	s_del(&data);
	return (out);
}

/*
**  ----------------------------------------------------------------------------
**
**	S_fill
**
**	Create a new string of `b_size` and fill it with the string `data`.
**	'0' = format with zeros instead of space.
**	'-' = left adjust
**
**  ----------------------------------------------------------------------------
*/
