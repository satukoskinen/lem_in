#ifndef CSTR_H
# define CSTR_H
# define READLINE_MAX_BUFF 1
# define READLINE_MAX_FD 2

# include "../../../inc/types.h"
# include "../../../inc/stdinc.h"

t_int64		s_toi(const char *str);
char		*s_cat(char *dest, const char *src);
char		*s_ncat(char *dest, const char *src, t_uint64 n);
t_uint64	s_lcat(char *dst, const char *src, t_uint64 size);
char		*s_rev(char *str);
char		*s_chr(const char *s, int c);
char		*s_rchr(const char *s, int c);
int			s_cmp(const char *s1, const char *s2);
int			s_ncmp(const char *s1, const char *s2, t_uint64 n);
char		*s_cpy(char *dest, const char *src);
char		*s_ncpy(char *dest, const char *src, t_uint64 n);
t_uint64	s_lcpy(char *dst, const char *src, t_uint64 dstsize);
char		*s_dup(const char *s);
char		*s_ndup(const char *s, t_uint64 n);
char		*s_cdup(const char *s1, char c);
char		*s_copy(char *str, t_size start, t_size end, t_size flag);
t_uint64	s_len(const char *s);
char		*s_str(const char *h, const char *n);
char		*s_nstr(const char *h, const char *n, t_uint64 len);
char		*s_new(t_uint64 size);
void		s_del(char **as);
void		s_clr(char *s);
void		s_iter(char **ref, int (*fptr)(int c));
void		s_iteri(char *s, void (*f)(unsigned int, char *));
char		*s_map(char const *s, char (*f)(char));
char		*s_mapi(char const *s, char (*f)(unsigned int, char));
int			s_equ(char const *s1, char const *s2);
int			s_nequ(char const *s1, char const *s2, t_uint64 n);
char		*s_sub(char const *s, unsigned int start, t_uint64 len);
char		*s_csub(char *s, char c);
char		*s_join(char const *s1, char const *s2);
char		*s_trim(char const *s);
char		**s_split(char const *s, char c);
int			s_lenc(char *s, char c);
int			s_sum(char *str);
char		*s_appendc(char *str, char c);
void		s_ctoc(char *str, int from, int to);
char		*s_newc(t_size size, int c);
char		*s_join_free(char *s1, char *s2, t_size flag);
char		*s_fill(char *data, t_size b_size, char *flags);
char		*s_cut(char *s, t_size size);
void		s_swp(char *a, char *b);
int			s_find_first(char *ref, char *src);
int			s_readline(const int fd, char **line);

#endif
