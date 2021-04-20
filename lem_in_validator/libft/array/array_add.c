/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 08:57:42 by skoskine          #+#    #+#             */
/*   Updated: 2021/04/11 11:44:29 by skoskine         ###   ########.fr       */
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

t_array	*array_add(t_array **array, void *data)
{
	if ((*array)->size == (*array)->capacity)
		*array = array_resize(array);
	if (!*array)
		return (NULL);
	ft_memcpy((*array)->data + (*array)->elem_size * (*array)->size, data,
		(*array)->elem_size);
	(*array)->size++;
	return (*array);
}
