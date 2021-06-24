/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 18:44:42 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/25 19:11:43 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	is_negative(int value)
{
	if (value < 0)
		return (1);
	else
		return (0);
}

char	*ft_itoa_base(int value, int base)
{
	char	*result;
	char	*digits;
	char	temp[32 + 1];
	int		i;

	if (base < 2 || base > 16)
		return (NULL);
	digits = "0123456789ABCDEF";
	i = 32;
	temp[i--] = '\0';
	if (value == 0)
		temp[i--] = '0';
	while (value != 0)
	{
		temp[i--] = digits[ft_abs(value % base)];
		value = value / base;
	}
	if (is_negative(value) && base == 10)
		temp[i--] = '-';
	result = (char *)malloc(32 - i + 1);
	if (result == NULL)
		return (NULL);
	return (ft_strcpy(result, &temp[i + 1]));
}
