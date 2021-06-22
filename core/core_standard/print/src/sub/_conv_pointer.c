/******************************************************************************
 *
 * \authors Satu Koskinen
 *
 * \brief
 *
 *****************************************************************************/

#include "../../../inc/core.h"
#include "../inc/print_internal.h"

int	_conv_pointer(t_data *specs, char **result)
{
	void		*ptr;
	t_uint64	value;
	char		*value_str;
	t_size		result_len;

	ptr = va_arg(*specs->ap, void *);
	value = (t_uint64)ptr;
	value_str = _uintmax_itoa_base(value, 16, 0);
	if (value_str == NULL)
		return (-1);
	result_len = s_len(value_str) + 2;
	specs->conversion = 'x';
	specs->alt_form = 1;
	specs->has_precision = 0;
	specs->precision = 0;
	if (specs->min_field_width > result_len)
		specs->min_field_width = specs->min_field_width - result_len;
	else
		specs->min_field_width = 0;
	result_len += specs->min_field_width;
	*result = _parse_int_result(specs, value_str, result_len);
	free(value_str);
	if (*result == NULL)
		return (-1);
	return ((int)result_len);
}
