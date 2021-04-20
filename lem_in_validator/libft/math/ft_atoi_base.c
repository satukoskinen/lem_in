/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 20:06:05 by skoskine          #+#    #+#             */
/*   Updated: 2021/04/09 10:00:04 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_digit_value(char c)
{
	int		value;
	char	*base_digits;

	value = 0;
	base_digits = "0123456789ABCDEF";
	while (base_digits[value] != c)
		value++;
	return (value);
}

int	ft_atoi_base(const char *str, int base)
{
	size_t	i;
	int		sign;
	int		result;

	i = 0;
	sign = 1;
	result = 0;
	if (base > 16)
		return (0);
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'A' && str[i] <= 'F'))
	{
		result = result * base + ft_digit_value(str[i]);
		i++;
	}
	return (sign * result);
}
