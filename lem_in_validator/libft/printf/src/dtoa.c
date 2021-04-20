/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dtoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 16:02:24 by skoskine          #+#    #+#             */
/*   Updated: 2021/04/09 10:10:49 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int	int_part_len(long double nbr)
{
	int	len;

	len = 1;
	while ((nbr > 0 && nbr / 10 >= 1.0) || (nbr < 0 && nbr / 10 <= -1.0))
	{
		len++;
		nbr /= 10;
	}
	return (len);
}

static int	add_integral_part(char *result, double int_part, int len)
{
	int		i;
	int		j;
	double	dbl_tmp;
	double	res;
	int		int_tmp;

	i = 0;
	if (ft_isnegative(int_part))
		result[i++] = '-';
	int_part = ft_fabs(int_part);
	while (len > 0)
	{
		dbl_tmp = int_part;
		j = 0;
		while (++j < len)
			dbl_tmp /= 10;
		int_tmp = (int)dbl_tmp;
		result[i++] = int_tmp + '0';
		len--;
		res = ft_dpow(10.0, len);
		res *= (double)int_tmp;
		int_part -= res;
	}
	return (i);
}

static int	add_fractional_part(char *result, long double frac_part,
int precision)
{
	int			i;

	if (precision == 0)
		return (0);
	frac_part = ft_fabsl(frac_part);
	i = 0;
	while (result[i])
		i++;
	result[i++] = '.';
	while (precision-- > 0)
	{
		frac_part *= 10;
		result[i++] = (int)frac_part + '0';
		frac_part -= (int)frac_part;
	}
	return (i);
}

static int	result_len(double int_part, size_t precision)
{
	int	len;

	len = int_part_len(int_part);
	if (ft_isnegative(int_part))
		len++;
	len += precision;
	if (precision > 0)
		len++;
	return (len);
}

char	*ft_dtoa(double nbr, size_t precision)
{
	char		*result;
	double		int_part;
	long double	frac_part;

	if (ft_isnan(nbr))
		return (ft_strdup("nan"));
	else if (ft_isposinf(nbr))
		return (ft_strdup("inf"));
	else if (ft_isneginf(nbr))
		return (ft_strdup("-inf"));
	frac_part = round_double(ft_modf(nbr, &int_part), precision);
	if (frac_part >= 1.0 || frac_part <= -1)
	{
		int_part += (int)frac_part;
		frac_part -= (int)frac_part;
	}
	else if (rounds_half_to_even(nbr, precision)
		&& (uintmax_t)(ft_fabs(int_part) + 1) % 2 == 0)
		int_part += ft_isnegative(nbr) * -1.0 + (1 - ft_isnegative(nbr)) * 1.0;
	result = (char *)ft_memalloc(result_len(int_part, precision) + 1);
	if (result == NULL)
		return (NULL);
	add_integral_part(result, int_part, int_part_len(int_part));
	add_fractional_part(result, frac_part, precision);
	return (result);
}
