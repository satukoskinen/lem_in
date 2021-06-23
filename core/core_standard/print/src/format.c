/******************************************************************************
 *
 * \authors Satu Koskinen
 *
 * \brief
 *
 *****************************************************************************/

#include "../../../inc/core.h"
#include "../inc/print_internal.h"

char	*format(const char *format, ...)
{
	char	*ret;
	va_list	ap;

	va_start(ap, format);
	ret = NULL;
	if (!(_vasprint(&ret, format, ap)))
		return (NULL);
	va_end(ap);
	return (ret);
}
