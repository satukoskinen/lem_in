/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parr_add_mult.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/05/23 21:26:54 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/core.h"

t_ssize	parr_add_mult(t_parray *arr, t_size len, ...)
{
	va_list	ap;

	va_start(ap, len);
	while (len--)
	{
		if (!(parr_add_last(arr, va_arg(ap, void *))))
			return (CR_FAIL);
	}
	va_end(ap);
	return (arr->len);
}

/*
**  ----------------------------------------------------------------------------
**
**	PARR_ADD_MULT
**
**	Add `len` rawbers to a dynamic array.
**
**  ----------------------------------------------------------------------------
*/
