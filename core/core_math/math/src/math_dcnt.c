/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_dcnt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 19:59:53 by jkoskela          #+#    #+#             */
/*   Updated: 2021/05/20 21:57:40 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/core.h"

t_size	math_dcnt(t_uint64 nb, t_uint64 base)
{
	return ((t_uint64)((math_log(nb) / math_log(base)) + 1));
}

/*
**  ----------------------------------------------------------------------------
**
**	math__digits_base
**
**	Calculate number of digits in `nb` in `base`. floor(log(nb) / log(base)
**
**  ----------------------------------------------------------------------------
*/
