/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_sum.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 20:15:15 by jkoskela          #+#    #+#             */
/*   Updated: 2021/05/11 09:05:44 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cstr.h"

int	s_sum(char *str)
{
	int		out;
	int		i;

	out = 0;
	i = 0;
	while (str[i])
	{
		out += str[i];
		i++;
	}
	return (out);
}

/*
**  ----------------------------------------------------------------------------
**
**	S_sum
**
**	Return the sum of all elements in string `str`.
**
**  ----------------------------------------------------------------------------
*/