/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_insert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 08:57:50 by skoskine          #+#    #+#             */
/*   Updated: 2021/04/17 12:00:01 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"
#include "libft.h"

static t_array	*array_resize(t_array **array)
{
	t_array	*new;

	new = array_new((*array)->capacity * 2, (*array)->elem_size);
	if (!new)
	{
		array_del(array);
		return (NULL);
	}
	ft_memcpy(new->data, (*array)->data, (*array)->elem_size * (*array)->size);
	new->size = (*array)->size;
	array_del(array);
	*array = new;
	return (*array);
}

t_array	*array_insert(t_array **array, void *data, size_t i)
{
	if ((*array)->size == (*array)->capacity)
		*array = array_resize(array);
	if (!*array)
		return (NULL);
	if (i > (*array)->size)
		i = (*array)->size;
	if (i != (*array)->size)
	{
		ft_memmove((*array)->data + (*array)->elem_size * (i + 1),
			(*array)->data + (*array)->elem_size * i,
			((*array)->size - i) * (*array)->elem_size);
	}
	ft_memcpy((*array)->data + (*array)->elem_size * i,
		data, (*array)->elem_size);
	(*array)->size++;
	return (*array);
}
