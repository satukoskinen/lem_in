/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_remove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 22:29:07 by skoskine          #+#    #+#             */
/*   Updated: 2021/06/22 13:51:25 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"
#include "libft.h"

void	array_remove(t_array *array, t_size i)
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
