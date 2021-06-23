/******************************************************************************
 *
 * \authors Satu Koskinen
 *
 * \brief
 *
 *****************************************************************************/

#ifndef PRINT_H
# define PRINT_H

# include "../../../inc/stdinc.h"

int		print(const char *format, ...);
int		print_fd(int fd, const char *format, ...);
int		print_file(const char *file, const char *format, ...);
char	*format(const char *format, ...);

#endif
