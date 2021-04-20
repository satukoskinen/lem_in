/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 18:10:54 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/25 18:44:10 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	number_length(int nbr)
{
	int	length;

	length = 1;
	if (nbr < 0)
		length++;
	while (nbr / 10 != 0)
	{
		length++;
		nbr /= 10;
	}
	return (length);
}

char	*ft_itoa(int nbr)
{
	char	*str;
	int		i;
	int		length;
	int		div;

	i = 0;
	length = number_length(nbr);
	str = malloc(sizeof(*str) * (length + 1));
	if (str == NULL)
		return (NULL);
	if (nbr < 0)
	{
		str[i++] = '-';
		length--;
	}
	while (length > 0)
	{
		div = ft_power(10, length - 1);
		str[i] = ft_abs(nbr / div) + 48;
		nbr %= div;
		i++;
		length--;
	}
	str[i] = '\0';
	return (str);
}
