/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_signed_integers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 09:39:00 by skoskine          #+#    #+#             */
/*   Updated: 2021/04/09 10:20:42 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>

static intmax_t	get_signed_arg(t_data *specs, va_list *ap)
{
	intmax_t	value;

	if (ft_strcmp(specs->length_modifier, "hh") == 0)
		value = (signed char)va_arg(*ap, int);
	else if (ft_strcmp(specs->length_modifier, "h") == 0)
		value = (short)va_arg(*ap, int);
	else if (ft_strcmp(specs->length_modifier, "ll") == 0)
		value = va_arg(*ap, long long);
	else if (ft_strcmp(specs->length_modifier, "l") == 0)
		value = va_arg(*ap, long);
	else
		value = va_arg(*ap, int);
	return (value);
}

static size_t	update_int_specs(t_data *specs, intmax_t value, char *value_str)
{
	size_t	len;

	if (value == 0)
		specs->is_zero = 1;
	if (value < 0)
		specs->is_negative = 1;
	len = ft_strlen(value_str);
	if (specs->is_zero && specs->zero_precision)
		len = 0;
	if (specs->has_precision)
		specs->zero_padding = 0;
	if (specs->precision > len - specs->is_negative)
		specs->precision = specs->precision - len + specs->is_negative;
	else
		specs->precision = 0;
	len += specs->precision;
	if (value >= 0 && (specs->plus_signed || specs->blank_signed))
		len += 1;
	if (specs->min_field_width > len)
		specs->min_field_width = specs->min_field_width - len;
	else
		specs->min_field_width = 0;
	len += specs->min_field_width;
	return (len);
}

int	parse_signed_ints(t_data *specs, va_list *ap, char **result)
{
	intmax_t	value;
	char		*value_str;
	size_t		len;

	value = get_signed_arg(specs, ap);
	value_str = ft_intmax_itoa_base(value, 10);
	if (value_str == NULL)
		return (-1);
	len = update_int_specs(specs, value, value_str);
	*result = parse_int_result(specs, value_str, len);
	free(value_str);
	if (*result == NULL)
		return (-1);
	return (len);
}
