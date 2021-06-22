/******************************************************************************
 *
 * \authors Satu Koskinen
 *
 * \brief
 *
 *****************************************************************************/

#include "../../../inc/core.h"
#include "../inc/print_internal.h"

t_size	_add_number(t_data *specs, char *number, char *result)
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

t_size	_add_padding(t_size len, char c, char *result)
{
	t_size	i;

	i = 0;
	while (i < len)
		result[i++] = c;
	return (i);
}

t_size	_add_prefix(t_data *specs, char *result)
{
	t_size	i;

	i = 0;
	if (specs->is_negative)
		result[i++] = '-';
	else if (s_chr("difF", specs->conversion)
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

char	*_parse_int_result(t_data *specs, char *number, t_size result_len)
{
	char	*result;
	t_size	i;

	result = (char *)malloc(sizeof(char) * (result_len + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	if (specs->min_field_width > 0 && !specs->zero_padding
		&& !specs->neg_field_width)
		i += _add_padding(specs->min_field_width, ' ', &result[i]);
	i += _add_prefix(specs, &result[i]);
	if (specs->min_field_width > 0 && specs->zero_padding
		&& !specs->neg_field_width)
		i += _add_padding(specs->min_field_width, '0', &result[i]);
	if (specs->precision > 0)
		i += _add_padding(specs->precision, '0', &result[i]);
	if (!(specs->zero_precision && specs->is_zero))
		i += _add_number(specs, number, &result[i]);
	if (specs->min_field_width > 0 && specs->neg_field_width)
		i += _add_padding(specs->min_field_width, ' ', &result[i]);
	result[i] = '\0';
	return (result);
}
