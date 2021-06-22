/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 22:17:11 by skoskine          #+#    #+#             */
/*   Updated: 2021/06/22 13:51:25 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H

# include <string.h>

typedef struct s_array
{
	void		*data;
	t_size		elem_size;
	t_size		capacity;
	t_size		size;
}				t_array;

t_array			*array_new(t_size capacity, t_size elem_size);
void			*array_get(t_array *array, t_size i);
int				array_indexof(t_array *array, void *data);
t_array			*array_add(t_array **array, void *data);
t_array			*array_insert(t_array **array, void *data, t_size i);
void			array_remove(t_array *array, t_size i);
void			array_del(t_array **array);
int				array_is_empty(t_array *array);
t_size			array_size(t_array *array);
t_array			*array_add(t_array **array, void *data);

#endif
