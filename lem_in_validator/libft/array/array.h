/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 22:17:11 by skoskine          #+#    #+#             */
/*   Updated: 2021/04/09 09:46:58 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H

# include <string.h>

typedef struct s_array
{
	void		*data;
	size_t		elem_size;
	size_t		capacity;
	size_t		size;
}				t_array;

t_array			*array_new(size_t capacity, size_t elem_size);
void			*array_get(t_array *array, size_t i);
int				array_indexof(t_array *array, void *data);
t_array			*array_add(t_array **array, void *data);
t_array			*array_insert(t_array **array, void *data, size_t i);
void			array_remove(t_array *array, size_t i);
void			array_del(t_array **array);
int				array_is_empty(t_array *array);
size_t			array_size(t_array *array);
t_array			*array_add(t_array **array, void *data);

#endif
