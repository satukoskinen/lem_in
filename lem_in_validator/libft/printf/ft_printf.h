/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 09:35:48 by skoskine          #+#    #+#             */
/*   Updated: 2021/06/22 13:51:25 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>

typedef struct s_data
{
	int		alt_form;
	int		zero_padding;
	int		neg_field_width;
	int		blank_signed;
	int		plus_signed;
	t_size	min_field_width;
	int		has_precision;
	t_size	precision;
	int		zero_precision;
	char	length_modifier[3];
	char	conversion;
	int		is_negative;
	int		is_zero;
}			t_data;

int				ft_vasprintf(char **ret, const char *format, va_list ap);
int				ft_asprintf(char **ret, const char *format, ...);
int				ft_dprintf(int fd, const char *format, ...);
int				ft_printf(const char *format, ...);
int				parse(const char *format, va_list *ap, char **result);
int				get_conversion_specs(t_data *specs, const char *format);
int				parse_percentage(t_data *specs, char **result);
int				parse_string(t_data *specs, char *str, char **result);
int				parse_char(t_data *specs, char c, char **result);
int				parse_pointer(t_data *specs, void *ptr, char **result);
int				parse_ints(t_data *specs, va_list *ap, char **result);
int				parse_unsigned_ints(t_data *specs, va_list *ap, char **result);
int				parse_signed_ints(t_data *specs, va_list *ap, char **result);
int				parse_doubles(t_data *specs, va_list *ap, char **result);
int				parse_double(t_data *specs, double value, char **result);
int				parse_long_double(t_data *specs, long double value,
					char **result);
char			*parse_int_result(t_data *specs, char *number,
					t_size result_len);
t_size			add_padding(t_size len, char c, char *result);
t_size			add_prefix(t_data *specs, char *result);
t_size			add_number(t_data *specs, char *number, char *result);
char			*ft_dtoa(double nbr, t_size precision);
long double		round_double(double nbr, t_size precision);
int				rounds_half_to_even(double nbr, t_size precision);

#endif
