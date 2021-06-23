#include "../inc/string.h"

static t_int64	verify_base_nbr(char c, int base)
{
	if (base <= 10)
		return (c >= '0' && c <= '9');
	return ((c >= '0' && c <= '9')
		|| (c >= 'A' && c <= ('A' + base - 10))
		|| (c >= 'a' && c <= ('a' + base - 10)));
}

t_int64	str_toi_base(const t_str str, t_int64 base)
{
	t_int64		nbr;
	int			sign;
	t_size		i;

	if (!str.raw.data || (base < 2 || base > 16))
		return (0);
	i = 0;
	nbr = 0;
	sign = 1;
	while (is_wspace(str.raw.data[i]) || str.raw.data[i] == '+')
		i++;
	if (str.raw.data[i++] == '-')
		sign *= -1;
	while (str.raw.data[i] && verify_base_nbr(str.raw.data[i], base))
	{
		if (str.raw.data[i] >= 'A' && 'F' >= str.raw.data[i])
			nbr = (nbr * base) + (str.raw.data[i] - 'A' + 10);
		else if (str.raw.data[i] >= 'a' && 'f' >= str.raw.data[i])
			nbr = (nbr * base) + (str.raw.data[i] - 'a' + 10);
		else
			nbr = (nbr * base) + (str.raw.data[i] - '0');
		i += 1;
	}
	return (nbr * sign);
}
