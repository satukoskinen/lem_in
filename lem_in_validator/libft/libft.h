/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 16:43:42 by skoskine          #+#    #+#             */
/*   Updated: 2021/06/22 13:51:25 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <inttypes.h>
# include <stdarg.h>

# define BUFF_SIZE 1

typedef struct s_list
{
	void			*content;
	t_size			content_size;
	struct s_list	*next;
}					t_list;

int					ft_abs(int n);
int					ft_atoi(const char *str);
long long int		ft_atoll(const char *str);
int					ft_atoi_base(const char *str, int base);
void				ft_bzero(void *s, t_size n);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_isspace(int c);
char				*ft_itoa(int n);
char				*ft_itoa_base(int n, int base);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void *, t_size));
void				ft_lstdelone(t_list **alst, void (*del)(void *, t_size));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, t_size content_size);
void				ft_lstpushback(t_list *alst, t_list *new);
int					ft_lstsize(t_list *lst);
void				*ft_memalloc(t_size size);
void				*ft_memccpy(void *dst, const void *src, int c, t_size n);
void				*ft_memchr(const void *s, int c, t_size n);
int					ft_memcmp(const void *s1, const void *s2, t_size n);
void				*ft_memcpy(void *dst, const void *src, t_size n);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dst, const void *src, t_size len);
void				*ft_memset(void *b, int c, t_size len);
int					ft_power(int base, int power);
void				ft_putchar_fd(char c, int fd);
void				ft_putchar(char c);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putendl(char const *s);
void				ft_putnbr_fd(int n, int fd);
void				ft_putnbr(int n);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putstr(char const *s);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strchr(const char *s, int c);
void				ft_strclr(char *s);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);
void				ft_strdel(char **as);
char				*ft_strdup(const char *s1);
int					ft_strequ(char const *s1, char const *s2);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
t_size				ft_strlcat(char *dst, const char *src, t_size dstsize);
t_size				ft_strlen(const char *s);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *s1, const char *s2, t_size n);
int					ft_strncmp(const char *s1, const char *s2, t_size n);
char				*ft_strncpy(char *dst, const char *src, t_size len);
int					ft_strnequ(char const *s1, char const *s2, t_size n);
char				*ft_strnew(t_size size);
char				*ft_strnstr(const char *haystack, const char *needle,
						t_size len);
char				*ft_strrchr(const char *s, int c);
char				**ft_strsplit(char const *s, char c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strsub(char const *s, unsigned int start, t_size len);
char				*ft_strtrim(char const *s);
int					ft_tolower(int c);
int					ft_toupper(int c);
void				*ft_realloc(void *ptr, t_size ptr_size, t_size size);
void				*ft_calloc(t_size count, t_size size);
char				*ft_uintmax_itoa_base(uintmax_t n, int base, int uppercase);
char				*ft_intmax_itoa_base(intmax_t n, int base);
double				ft_dpow(double base, int power);
int					ft_isnegative(double nbr);
int					ft_isnan(double nbr);
int					ft_isposinf(double nbr);
int					ft_isneginf(double nbr);
double				ft_modf(double value, double *iptr);
double				ft_fabs(double nbr);
long double			ft_fabsl(long double nbr);
uintmax_t			ft_uintmax_pow(int base, int power);
int					get_next_line(const int fd, char **line);
double				ft_sqrt(double value);

int					ft_vasprintf(char **ret, const char *format, va_list ap);
int					ft_asprintf(char **ret, const char *format, ...);
int					ft_dprintf(int fd, const char *format, ...);
int					ft_printf(const char *format, ...);

#endif
