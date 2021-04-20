/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_remove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 22:29:07 by skoskine          #+#    #+#             */
/*   Updated: 2021/04/09 09:46:24 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"
#include "libft.h"

void	array_remove(t_array *array, size_t i)
{
	if (i >= array->size)
		return ;
	if (i == array->size - 1)
		array->size--;
	else
	{
		ft_memcpy(array->data + i * array->elem_size,
			array->data + (i + 1) * array->elem_size,
			(array->size - i - 1) * array->elem_size);
		array->size--;
	}
}
