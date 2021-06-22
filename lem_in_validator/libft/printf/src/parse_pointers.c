/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pointers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 19:08:42 by skoskine          #+#    #+#             */
/*   Updated: 2021/06/22 13:51:25 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdlib.h>

int	parse_pointer(t_data *specs, void *ptr, char **result)
{
	uintmax_t	value;
	char		*value_str;
	t_size		result_len;

	value = (uintmax_t)ptr;
	value_str = ft_uintmax_itoa_base(value, 16, 0);
	if (value_str == NULL)
		return (-1);
	result_len = ft_strlen(value_str) + 2;
	specs->conversion = 'x';
	specs->alt_form = 1;
	specs->has_precision = 0;
	specs->precision = 0;
	if (specs->min_field_width > result_len)
		specs->min_field_width = specs->min_field_width - result_len;
	else
		specs->min_field_width = 0;
	result_len += specs->min_field_width;
	*result = parse_int_result(specs, value_str, result_len);
	free(value_str);
	if (*result == NULL)
		return (-1);
	return (result_len);
}
