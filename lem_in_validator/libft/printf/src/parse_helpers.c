/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 12:56:17 by skoskine          #+#    #+#             */
/*   Updated: 2021/06/22 13:51:25 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>

t_size	add_number(t_data *specs, char *number, char *result)
{
	t_size	i;

	i = 0;
	if (specs->is_negative)
		number++;
	while (number[i])
	{
		result[i] = number[i];
		i++;
	}
	return (i);
}

t_size	add_padding(t_size len, char c, char *result)
{
	t_size	i;

	i = 0;
	while (i < len)
		result[i++] = c;
	return (i);
}

t_size	add_prefix(t_data *specs, char *result)
{
	t_size	i;

	i = 0;
	if (specs->is_negative)
		result[i++] = '-';
	else if (ft_strchr("difF", specs->conversion)
		&& (specs->blank_signed || specs->plus_signed))
	{
		if (specs->plus_signed)
			result[i++] = '+';
		else
			result[i++] = ' ';
	}
	else if (specs->conversion == 'x' && specs->alt_form && !specs->is_zero)
	{
		result[i++] = '0';
		result[i++] = 'x';
	}
	else if (specs->conversion == 'X' && specs->alt_form && !specs->is_zero)
	{
		result[i++] = '0';
		result[i++] = 'X';
	}
	return (i);
}

char	*parse_int_result(t_data *specs, char *number, t_size result_len)
{
	char	*result;
	t_size	i;

	result = (char *)malloc(sizeof(char) * (result_len + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	if (specs->min_field_width > 0 && !specs->zero_padding
		&& !specs->neg_field_width)
		i += add_padding(specs->min_field_width, ' ', &result[i]);
	i += add_prefix(specs, &result[i]);
	if (specs->min_field_width > 0 && specs->zero_padding
		&& !specs->neg_field_width)
		i += add_padding(specs->min_field_width, '0', &result[i]);
	if (specs->precision > 0)
		i += add_padding(specs->precision, '0', &result[i]);
	if (!(specs->zero_precision && specs->is_zero))
		i += add_number(specs, number, &result[i]);
	if (specs->min_field_width > 0 && specs->neg_field_width)
		i += add_padding(specs->min_field_width, ' ', &result[i]);
	result[i] = '\0';
	return (result);
}
