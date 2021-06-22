/******************************************************************************
 *
 * \authors Julius Koskela
 *
 * \brief
 *
 *****************************************************************************/

#ifndef MATH_H
# define MATH_H

# include "../../../core_containers/array/inc/array.h"
# include "../../../inc/stdinc.h"

double				math_rad(double dgr);
double				math_dgr(double rad);
double				math_sqrt(double n);
t_int64				math_log(t_int64 n);
int					math_intlen(t_int64 n);
double				math_fabs(double n);
long double			math_flabs(long double n);
double				math_pow(double base, double exp);
double				math_sin(double x, t_int64 p);
double				math_cos(double x, t_int64 p);
t_int64				math_fac(t_int64 n);
t_uint64			math_prime(t_uint64 n);
t_uint64			math_nextprime(t_uint64 n);
t_array				math_primefac(t_uint64 n);
t_size				math_dcnt(t_uint64 nb, t_uint64 base);
double				math_ceil(double f);
double				math_floor(double x);
double				math_modf(double x, double *iptr);
long double			math_modl(long double x, long double *iptr);
t_int64				math_abs(t_int64 n);
int					math_sign(t_int64 n);
int					math_fsign(long double n);
long double			math_roundl(long double x);
t_int64				math_ipow(t_int64 base, t_int64 exp);

#endif
