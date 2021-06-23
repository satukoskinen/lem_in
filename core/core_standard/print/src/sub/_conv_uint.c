/******************************************************************************
 *
 * \authors Satu Koskinen
 *
 * \brief
 *
 *****************************************************************************/

#include "../../../inc/core.h"
#include "../inc/print_internal.h"

static char	*get_value_string(t_data *specs, t_uint64 value)
{
	char	*result;

	if (specs->conversion == 'o')
		result = _uintmax_itoa_base(value, 8, 0);
	else if (specs->conversion == 'u')
		result = _uintmax_itoa_base(value, 10, 0);
	else if (specs->conversion == 'x')
		result = _uintmax_itoa_base(value, 16, 0);
	else
		result = _uintmax_itoa_base(value, 16, 1);
	return (result);
}

static t_uint64	get_unsigned_arg(t_data *specs, va_list *ap)
{
	t_uint64	value;

	if (s_cmp(specs->length_modifier, "hh") == 0)
		value = (unsigned char)va_arg(*ap, unsigned int);
	else if (s_cmp(specs->length_modifier, "h") == 0)
		value = (unsigned short)va_arg(*ap, unsigned int);
	else if (s_cmp(specs->length_modifier, "ll") == 0)
		value = va_arg(*ap, unsigned long long);
	else if (s_cmp(specs->length_modifier, "l") == 0)
		value = va_arg(*ap, unsigned long);
	else
		value = (t_uint64)va_arg(*ap, unsigned int);
	return (value);
}

static t_size	update_uint_specs(t_data *specs,
	t_uint64 value, char *value_str)
{
	t_size	len;

	if (value == 0)
		specs->is_zero = 1;
	if (specs->has_precision)
		specs->zero_padding = 0;
	len = s_len(value_str);
	if (specs->is_zero && specs->zero_precision)
		len = 0;
	if (specs->precision > len)
		specs->precision = specs->precision - len;
	else
		specs->precision = 0;
	if (specs->alt_form && specs->conversion == 'o' && specs->precision == 0
		&& (!specs->is_zero || specs->zero_precision))
		specs->precision++;
	len += specs->precision;
	if (specs->alt_form && s_chr("xX", specs->conversion)
		&& !specs->is_zero)
		len += 2;
	if (specs->min_field_width > len)
		specs->min_field_width = specs->min_field_width - len;
	else
		specs->min_field_width = 0;
	return (len + specs->min_field_width);
}

int	_conv_uint(t_data *specs, char **result)
{
	t_uint64	value;
	char		*value_str;
	t_size		len;

	value = get_unsigned_arg(specs, specs->ap);
	value_str = get_value_string(specs, value);
	if (value_str == NULL)
		return (-1);
	len = update_uint_specs(specs, value, value_str);
	*result = _parse_int_result(specs, value_str, len);
	free(value_str);
	if (*result == NULL)
		return (-1);
	return ((int)len);
}
