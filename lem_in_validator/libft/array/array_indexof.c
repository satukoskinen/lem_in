/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_indexof.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 08:58:01 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/28 12:26:39 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"
#include "libft.h"

int	array_indexof(t_array *array, void *data)
{
	size_t	i;

	i = 0;
	while (i < array->size)
	{
		if (!ft_memcmp(array_get(array, i), data, array->elem_size))
			return (i);
		i++;
	}
	return (-1);
}
