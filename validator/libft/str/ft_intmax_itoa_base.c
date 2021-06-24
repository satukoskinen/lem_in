/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intmax_itoa_base.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 16:56:14 by skoskine          #+#    #+#             */
/*   Updated: 2021/04/09 10:57:38 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <inttypes.h>
#include "libft.h"

static int	is_negative(intmax_t value)
{
	if (value < 0)
		return (1);
	else
		return (0);
}

char	*ft_intmax_itoa_base(intmax_t value, int base)
{
	char	*result;
	char	*digits;
	char	temp[64 + 1];
	int		i;
	int		is_neg;

	if (base < 2 || base > 16)
		return (NULL);
	digits = "0123456789ABCDEF";
	i = 64;
	is_neg = is_negative(value);
	temp[i--] = '\0';
	if (value == 0)
		temp[i--] = '0';
	while (value != 0)
	{
		temp[i--] = digits[ft_abs(value % base)];
		value = value / base;
	}
	if (is_neg && base == 10)
		temp[i--] = '-';
	result = (char *)malloc(64 - i + 1);
	if (result == NULL)
		return (NULL);
	return (ft_strcpy(result, &temp[i + 1]));
}
