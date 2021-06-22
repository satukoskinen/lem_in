/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_ceil.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 21:53:22 by jkoskela          #+#    #+#             */
/*   Updated: 2021/05/20 21:57:40 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/core.h"

double	math_ceil(double f)
{
	t_uint64	input;
	int			exponent;
	int			fractional_bits;
	t_uint64	integral_mask;
	t_uint64	output;

	mcpy(&input, &f, 4);
	exponent = ((input >> 23) & 255) - 127;
	if (exponent < 0)
		return (f > 0);
	fractional_bits = 23 - exponent;
	if (fractional_bits <= 0)
		return (f);
	integral_mask = 0xffffffff << fractional_bits;
	output = input & integral_mask;
	mcpy(&f, &output, 4);
	if (f > 0 && output != input)
		++f;
	return (f);
}

/*
**  ----------------------------------------------------------------------------
**
**	math_ceil
**
**	Ceiling function maps to the least integer greater than or equal to
**
**	Logic:
**
**	1. Small numbers get rounded to 0 or 1, depending on their sign
**	2. Numbers without fractional bits are mapped to themselves
**	3. Round the number down by masking out the fractional bits
**	4. Positive numbers need to be rounded up, not down
**
**  ----------------------------------------------------------------------------
*/
