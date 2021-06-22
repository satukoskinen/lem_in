/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 22:20:21 by skoskine          #+#    #+#             */
/*   Updated: 2021/06/22 13:51:25 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "array.h"

t_array	*array_new(t_size capacity, t_size elem_size)
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
