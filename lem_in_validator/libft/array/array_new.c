/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 22:20:21 by skoskine          #+#    #+#             */
/*   Updated: 2021/04/09 09:47:13 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "array.h"

t_array	*array_new(size_t capacity, size_t elem_size)
{
	t_array	*new;

	new = (t_array *)malloc(sizeof(t_array));
	if (new == NULL)
		return (NULL);
	new->data = malloc(elem_size * capacity);
	if (new->data == NULL)
	{
		free(new);
		return (NULL);
	}
	new->capacity = capacity;
	new->elem_size = elem_size;
	new->size = 0;
	return (new);
}
