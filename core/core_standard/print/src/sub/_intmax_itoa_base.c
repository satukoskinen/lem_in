/******************************************************************************
 *
 * \authors Satu Koskinen
 *
 * \brief
 *
 *****************************************************************************/

#include "../../../inc/core.h"
#include "../inc/print_internal.h"

char	*_intmax_itoa_base(t_int64 value, int base)
{
	char	*result;
	char	*digits;
	char	temp[64 + 1];
	int		i;
	int		negative;

	if (base < 2 || base > 16)
		return (NULL);
	digits = "0123456789ABCDEF";
	i = 64;
	negative = is_neg(value);
	temp[i--] = '\0';
	if (value == 0)
		temp[i--] = '0';
	while (value != 0)
	{
		temp[i--] = digits[_abs(value % base)];
		value = value / base;
	}
	if (negative && base == 10)
		temp[i--] = '-';
	result = (char *)malloc(64 - i + 1);
	if (result == NULL)
		return (NULL);
	return (s_cpy(result, &temp[i + 1]));
}
