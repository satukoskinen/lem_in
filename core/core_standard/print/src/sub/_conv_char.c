/******************************************************************************
 *
 * \authors Satu Koskinen
 *
 * \brief
 *
 *****************************************************************************/

#include "../../../inc/core.h"
#include "../inc/print_internal.h"

static char	*parse_str_result(t_data *specs, char *str, t_size str_len)
{
	t_size	result_len;
	t_size	i;
	t_size	j;
	char	*result;

	result_len = str_len + specs->min_field_width;
	result = (char *)malloc(sizeof(char) * (result_len + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	if (specs->min_field_width > 0 && !specs->zero_padding
		&& !specs->neg_field_width)
		i += _add_padding(specs->min_field_width, ' ', &result[i]);
	else if (specs->min_field_width > 0 && specs->zero_padding
		&& !specs->neg_field_width)
		i += _add_padding(specs->min_field_width, '0', &result[i]);
	j = 0;
	while (j < str_len)
		result[i++] = str[j++];
	if (specs->min_field_width > 0 && specs->neg_field_width)
		i += _add_padding(specs->min_field_width, ' ', &result[i]);
	result[i] = '\0';
	return (result);
}

static t_size	update_str_specs(t_data *specs, char *str)
{
	t_size	len;

	if (str == NULL)
	{
		if (specs->has_precision && specs->precision < 6)
			len = specs->precision;
		else
			len = 6;
	}
	else
	{
		len = s_len(str);
		if (specs->has_precision && specs->precision < len)
			len = specs->precision;
	}
	if (specs->min_field_width > len)
		specs->min_field_width = specs->min_field_width - len;
	else
		specs->min_field_width = 0;
	return (len);
}

int	_conv_string(t_data *specs, char **result)
{
	char	*str;
	t_size	str_len;

	str = (char *)va_arg(*specs->ap, char *);
	str_len = update_str_specs(specs, str);
	if (str == NULL)
		*result = parse_str_result(specs, "(null)", str_len);
	else
		*result = parse_str_result(specs, str, str_len);
	if (*result == NULL)
		return (-1);
	return ((int)s_len(*result));
}

int	_conv_char(t_data *specs, char **result)
{
	char	c;

	if (specs->conversion == '%')
		c = '%';
	else
		c = (char)va_arg(*specs->ap, int);
	if (specs->min_field_width >= 1)
		specs->min_field_width--;
	*result = parse_str_result(specs, &c, 1);
	if (*result == NULL)
		return (-1);
	return ((int)specs->min_field_width + 1);
}
