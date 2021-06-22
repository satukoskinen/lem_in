/******************************************************************************
 *
 * \authors Julius Koskela
 *
 * \brief A hash map implementation library.
 *
 *****************************************************************************/

#ifndef RAW_H
# define RAW_H

# include "../../../inc/types.h"

t_hraw		hraw_range(t_raw src, t_size s, t_size t);
t_raw		raw_new(t_size bytes);
t_ssize		raw_realloc(t_raw *raw, t_size new_size);
void		raw_free(t_raw *raw);
t_raw		raw_cpy(t_raw dst, t_raw src, t_size size);
t_raw		raw_assign(void *src, t_size size);
t_hraw		raw_chr(t_raw src, t_raw b);
void		raw_print(t_raw src);

#endif
