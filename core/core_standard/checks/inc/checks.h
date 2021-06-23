/******************************************************************************
 *
 * \authors Julius Koskela, Satu Koskinen
 *
 * \brief Dynamic array implementation library.
 *
 *****************************************************************************/

#ifndef CHECKS_H
# define CHECKS_H

int		is_alnum(int c);
int		is_alpha(int c);
int		is_ascii(int c);
int		is_digit(int c);
int		is_lower(int c);
int		is_nan(double n);
int		is_neg(t_int64 n);
int		is_negf(double n);
int		is_neginf(double n);
int		is_numeric(int c);
int		is_posinf(double n);
int		is_posinf(double n);
int		is_space(int c);
int		is_upper(int c);
int		is_wspace(char c);

#endif
