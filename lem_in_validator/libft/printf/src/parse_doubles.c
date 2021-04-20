/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_doubles.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 09:38:46 by skoskine          #+#    #+#             */
/*   Updated: 2021/04/09 10:20:13 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdarg.h>
#include <stdlib.h>

static int	get_int_part_len(char *value_str)
{
	int	len;

	len = 0;
	while (value_str[len] != '.' && value_str[len] != '\0')
		len++;
	if (value_str[0] == '-')
		len--;
	return (len);
}

char	*parse_double_result(t_data *specs, char *value_str, size_t len)
{
	char	*result;
	size_t	i;

	result = (char *)malloc(sizeof(char) * (len + 1));
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
	i += add_number(specs, value_str, &result[i]);
	if (specs->precision == 0 && specs->alt_form)
		result[i++] = '.';
	if (specs->min_field_width > 0 && specs->neg_field_width)
		i += add_padding(specs->min_field_width, ' ', &result[i]);
	result[i] = '\0';
	return (result);
}

int	get_result_length(t_data *specs, double value, char *value_str)
{
	size_t	len;

	if (ft_isnan(value) || ft_isposinf(value) || ft_isneginf(value))
		len = 3;
	else
	{
		len = get_int_part_len(value_str);
		if ((specs->precision == 0 && specs->alt_form) || specs->precision != 0)
			len++;
		len += specs->precision;
	}
	if (specs->is_negative)
		len++;
	else if (!specs->is_negative
		&& (specs->plus_signed || specs->blank_signed) && !ft_isnan(value))
		len++;
	return (len);
}

static void	update_double_specs(t_data *specs, double value)
{
	if (!specs->has_precision)
		specs->precision = 6;
	specs->is_negative = ft_isnegative(value);
	if (ft_isnan(value) || ft_isposinf(value) || ft_isneginf(value))
	{
		specs->precision = 0;
		specs->alt_form = 0;
		specs->zero_padding = 0;
	}
	if (ft_isnan(value))
	{
		specs->plus_signed = 0;
		specs->blank_signed = 0;
		specs->is_negative = 0;
	}
}

int	parse_doubles(t_data *specs, va_list *ap, char **result)
{
	double		value;
	char		*value_str;
	size_t		len;

	if (specs->length_modifier[0] == '\0' || specs->length_modifier[0] == 'l')
		value = va_arg(*ap, double);
	else
		value = (double)va_arg(*ap, long double);
	update_double_specs(specs, value);
	value_str = ft_dtoa(value, specs->precision);
	if (value_str == NULL)
		return (-1);
	len = get_result_length(specs, value, value_str);
	if (specs->min_field_width > len)
		specs->min_field_width = specs->min_field_width - len;
	else
		specs->min_field_width = 0;
	len += specs->min_field_width;
	*result = parse_double_result(specs, value_str, len);
	free(value_str);
	if (*result == NULL)
		return (-1);
	return (len);
}
