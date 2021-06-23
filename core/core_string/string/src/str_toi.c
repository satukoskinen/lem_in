#include "../inc/string.h"

t_int64	str_toi(const t_str str)
{
	const char	*ptr;
	t_int64		sign;
	t_int64		result;
	t_int64		i;

	ptr = (const char *)str.raw.data;
	sign = 1;
	result = 0;
	i = 0;
	while (is_space(ptr[i]))
		i++;
	if (ptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (ptr[i] == '+')
		i++;
	while (ptr[i] >= '0' && ptr[i] <= '9')
	{
		result = result * 10 + ptr[i] - 48;
		i++;
	}
	return (result * sign);
}
