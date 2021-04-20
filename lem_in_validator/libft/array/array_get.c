/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_get.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 08:55:13 by skoskine          #+#    #+#             */
/*   Updated: 2021/04/10 13:21:04 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"
#include <stdlib.h>

void	*array_get(t_array *array, size_t i)
{
	if (i >= array->size)
		return (NULL);
	return (array->data + array->elem_size * i);
}
