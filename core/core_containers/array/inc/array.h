#ifndef ARRAY_H
# define ARRAY_H

///////////////////////////////////////////////////////////////////////////////
///
/// \brief Dynamic array implementation library.
///
/// \authors Julius Koskela
///
///////////////////////////////////////////////////////////////////////////////

# include "../../../inc/types.h"
# include "../../../inc/config.h"
# include "../../../inc/const.h"
# include "../../../core_system/inc/system.h"
# include "../../../core_standard/print/inc/print.h"
# include "../../../core_containers/raw/inc/raw.h"
# include "../../../core_standard/memory/inc/memory.h"
# include "../../../core_containers/array/inc/array.h"
# include "../../../core_string/cstring/inc/cstr.h"

///////////////////////////////////////////////////////////////////////////////

t_array		arr_new(t_size len, t_size elem_size);
void		*arr_get(t_array *src, t_size index);
void		*arr_get_first(t_array *src);
void		*arr_get_last(t_array *src);
void		*arr_take(void *dst, t_array *src, t_size index);
void		*arr_take_first(void *dst, t_array *src);
void		*arr_take_last(void *dst, t_array *src);
t_ssize		arr_free(t_array *src);
t_ssize		arr_null(t_array *src);
t_ssize		arr_add(t_array *src, void *node, t_size index);
t_ssize		arr_add_first(t_array *src, void *node);
t_ssize		arr_add_last(t_array *src, void *node);
t_ssize		arr_add_mult(t_array *src, t_size count, ...);
t_ssize		arr_put(t_array *dst, void *src, t_size size);
t_ssize		arr_del(t_array *src, t_size index);
t_ssize		arr_del_first(t_array *src);
t_ssize		arr_del_last(t_array *src);
t_ssize		arr_find(t_array *src, void *key);
t_ssize		arr_search(t_array *src, t_array *key);
t_ssize		arr_copy(t_array *dst, t_array *src);
t_ssize		arr_join(t_array *dst, t_array *src);
t_ssize		arr_join_mult(t_array *dst, t_size count, ...);
t_ssize		arr_rotate(t_array *arr, t_ssize steps);
void		arr_print(t_array *src, char *format);
t_ssize		arr_iter(t_array *src,
				t_ssize (*f)(void *, t_size));
t_ssize		arr_iter_range(t_array *src, t_size start, t_size end,
				t_ssize (*f)(void *, t_size));
t_ssize		arr_find_by(t_array *arr, const void *key,
				t_ssize (*f)(const void *, const void *));
t_ssize		arr_parse(t_array *dst, t_array *src,
				t_ssize (*f)(t_array *, void *));
void		arr_sort(t_array *src,
				t_ssize (*f)(void *, void *));
///////////////////////////////////////////////////////////////////////////////

#endif
