/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parr.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 06:09:12 by jkoskela          #+#    #+#             */
/*   Updated: 2021/06/11 16:42:50 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARR_H
# define PARR_H

# include "../../../inc/types.h"

/*
**	---------------------------------------------------------------------------
**
**	General
*/

t_parray		parr_new(t_size size);
t_ssize			parr_free(t_parray *arr);
t_ssize			parr_grow(t_parray *arr, t_size new_size);
t_ssize			parr_null(t_parray *arr);

/*
**	---------------------------------------------------------------------------
**
**	Add or delete rawber(s)
*/

t_ssize			parr_add(t_parray *arr, void *node, t_size index);
t_ssize			parr_add_first(t_parray *arr, void *node);
t_ssize			parr_add_last(t_parray *arr, void *node);
t_ssize			parr_add_mult(t_parray *arr, t_size len, ...);
t_ssize			parr_assign(t_parray *dst, void **src, t_size size);
t_ssize			parr_del(t_parray *arr, t_size index);
t_ssize			parr_del_first(t_parray *arr);
t_ssize			parr_del_last(t_parray *arr);

/*
**	---------------------------------------------------------------------------
**
**	Get or take a rawber
*/

void			*parr_get(t_parray *arr, t_size index);
void			*parr_get_first(t_parray *arr);
void			*parr_get_last(t_parray *arr);
void			*parr_take(t_parray *arr, t_size index);
void			*parr_take_first(t_parray *arr);
void			*parr_take_last(t_parray *arr);

/*
**	---------------------------------------------------------------------------
**
**	Manipulation
*/

t_ssize			parr_copy(t_parray *dst, t_parray *src);
t_ssize			parr_join(t_parray *dst, t_size len, ...);
t_ssize			parr_split(t_parray *dst, t_parray *src);
t_ssize			parr_rotate(t_parray *arr, t_ssize steps);

/*
**	---------------------------------------------------------------------------
**
**	Templates
*/

t_ssize			parr_dup(t_parray *dst, t_parray *src, t_size size);
t_ssize			parr_read_file(t_parray *dst, char *filename);
t_ssize			parr_write_file(char *dst, t_parray *src, t_ssize flag,
					t_ssize (*f)(void *, void *));
t_ssize			parr_write(t_parray *dst, t_parray *src,
					t_ssize (*f)(void *, void *));
t_ssize			parr_search(t_parray *dst, t_parray *src, void *key,
					void *(*f)(void *, void *));
void			*parr_find(t_parray *src, void *key,
					void *(*f)(void *, void *));
t_ssize			parr_iter(t_parray *arr,
					t_ssize (*f)(void *, t_size));
t_ssize			parr_parse(t_parray *dst, t_parray *src,
					t_ssize (*f)(t_parray *, void *));

#endif
