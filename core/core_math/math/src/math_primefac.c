/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_primefac.c                                     :+:      :+:    :+:*/
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 04:03:45 by jkoskela          #+#    #+#             */
/*   Updated: 2021/05/11 09:28:07 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/core.h"

t_array	math_primefac(t_uint64 n)
{
	t_array		out;
	t_uint64	i;
	t_uint64	curr;

	while (n % 2 == 0)
	{
		curr = 2;
		arr_add_last(&out, &curr);
		n = n / 2;
	}
	i = 3;
	while (i <= math_sqrt(n))
	{
		while (n % i == 0)
		{
			arr_add_last(&out, &i);
			n = n / i;
		}
		i = i + 2;
	}
	if (n > 2)
	{
		arr_add_last(&out, &n);
	}
	return (out);
}

/*
**  ----------------------------------------------------------------------------
**
**	math_primefac
**
**	Calculates the prime factorials of `n` and returns a linked list with
**	the results.
**
**  ----------------------------------------------------------------------------
*/
