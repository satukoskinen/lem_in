#ifndef STRING_H
# define STRING_H

///////////////////////////////////////////////////////////////////////////////
///
/// \authors Julius Koskela
///
/// \brief A fast string implementation.
///
///////////////////////////////////////////////////////////////////////////////

/// Includes //////////////////////////////////////////////////////////////////

# include "../../../inc/types.h"
# include "../../../inc/config.h"
# include "../../../inc/const.h"
# include "../../../core_containers/raw/inc/raw.h"
# include "../../../core_standard/memory/inc/memory.h"
# include "../../../core_containers/array/inc/array.h"
# include "../../../core_string/cstring/inc/cstr.h"
# include "../../../core_standard/checks/inc/checks.h"

/// String ////////////////////////////////////////////////////////////////////

t_str	str_from_s(char *str);
void	str_free(t_str *str);
t_str	str_new(t_size len);
t_str	str_cpy(t_str dst, t_str src);
t_str	str_join(t_str dst, t_str src);
t_str	str_ncpy(t_str dst, t_str src, t_size len);
void	str_write(t_str str);
t_hstr	str_chr(t_str src, char c);
t_size	str_cmp(t_str s1, t_str s2);
void	str_rev(t_str *src);
t_int64	str_toi(const t_str str);
double	str_tof(const t_str str);
t_int64	str_toi_base(const t_str str, t_int64 base);

/// String Handle /////////////////////////////////////////////////////////////

t_hstr	hstr_assign(void *src, t_size size);
void	hstr_write(t_hstr str);
t_hstr	hstr_range(t_str src, t_size s, t_size t);

/// Page //////////////////////////////////////////////////////////////////////

t_page	page_new(t_size size);
t_str	page_get(t_page *src, t_size i);
t_ssize	page_read_file(t_page *dst, char *filename);
t_ssize	page_write_file(char *dst, t_page *src, t_ssize flag);
void	page_print(t_page p);
void	page_free(t_page *p);

///////////////////////////////////////////////////////////////////////////////

#endif
