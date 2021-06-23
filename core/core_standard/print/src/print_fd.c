/******************************************************************************
 *
 * \authors Satu Koskinen
 *
 * \brief
 *
 *****************************************************************************/

#include "../../../inc/core.h"
#include "../inc/print_internal.h"

int	print_fd(int fd, const char *format, ...)
{
	va_list	ap;
	char	*result;
	int		ret;

	result = NULL;
	va_start(ap, format);
	ret = _vasprint(&result, format, ap);
	va_end(ap);
	if (ret != -1)
		ret = write(fd, result, (t_size)ret);
	free(result);
	return (ret);
}
