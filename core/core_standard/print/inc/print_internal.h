/******************************************************************************
 *
 * \authors Satu Koskinen
 *
 * \brief
 *
 *****************************************************************************/

#ifndef PRINT_INTERNAL_H
# define PRINT_INTERNAL_H

# include "../../../inc/stdinc.h"
# include "../../../inc/types.h"

typedef struct s_data
{
	t_uint8		alt_form : 1;
	t_uint8		zero_padding : 1;
	t_uint8		neg_field_width : 1;
	t_uint8		blank_signed : 1;
	t_uint8		plus_signed : 1;
	t_uint8		has_precision : 1;
	t_uint8		zero_precision : 1;
	t_uint8		is_negative : 1;
	t_uint8		is_zero : 1;
	t_uint8		error : 1;
	char		conversion;
	char		length_modifier[3];
	t_size		precision;
	t_size		min_field_width;
	va_list		*ap;
}				t_data;

typedef union u_ret
{
	char		c;
	char		*cptr;
	t_str		str;
	t_int8		i8;
	t_int16		i16;
	t_int32		i32;
	t_int64		i64;
	t_uint8		u8;
	t_uint16	u16;
	t_uint32	u32;
	t_uint64	u64;
	float		f;
	double		d;
	long double	ld;
	void		*vptr;
}				t_ret;

static const char	g_types [] = "%cdiouxXbeEfFsSp";

typedef int			(*t_fptr)(t_data *, char **);

int				_conv_string(t_data *specs, char **result);
int				_conv_char(t_data *specs, char **result);
int				_conv_pointer(t_data *specs, char **result);
int				_conv_uint(t_data *specs, char **result);
int				_conv_int(t_data *specs, char **result);
int				_conv_double(t_data *specs, char **result);
int				_failure(t_data *specs, char **result);

static const t_fptr	g_type_conversions[] =
{
	_conv_char,
	_conv_char,
	_conv_int,
	_conv_int,
	_conv_uint,
	_conv_uint,
	_conv_uint,
	_conv_uint,
	_conv_uint,
	_conv_double,
	_conv_double,
	_conv_double,
	_conv_double,
	_conv_string,
	_conv_string,
	_conv_pointer,
	_failure
};

int				_vasprint(char **ret, const char *format, va_list ap);
int				_parse(const char *format, va_list *ap, char **result);
int				_get_conversion_specs(t_data *specs, const char *format);
int				_parse_percentage(t_data *specs, char **result);
int				_parse_double(t_data *specs, double value, char **result);
int				_parse_long_double(t_data *specs, long double value,
					char **result);
char			*_parse_int_result(t_data *specs, char *number,
					t_size result_len);
t_size			_add_padding(t_size len, char c, char *result);
t_size			_add_prefix(t_data *specs, char *result);
t_size			_add_number(t_data *specs, char *number, char *result);
char			*_dtoa(double nbr, t_size precision);
long double		_round_double(double nbr, t_size precision);
int				_rounds_half_to_even(double nbr, int precision);
int				_atoi(const char *str);
void			*_realloc(void *ptr, t_size ptr_size, t_size size);
char			*_uintmax_itoa_base(t_uint64 n, int base, int uppercase);
char			*_intmax_itoa_base(t_int64 n, int base);
double			_dpow(double base, int power);
double			_modf(double value, double *iptr);
int				_abs(int n);
double			_fabs(double nbr);
long double		_fabsl(long double nbr);
t_uint64		_uintmax_pow(int base, int power);
double			_sqrt(double value);

#endif
