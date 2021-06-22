/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 20:06:05 by skoskine          #+#    #+#             */
/*   Updated: 2021/06/22 13:51:25 by jkoskela         ###   ########.fr       */
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
	t_size	i;
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
