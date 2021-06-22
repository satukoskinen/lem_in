#include "../../inc/core.h"
#include "../inc/system_internal.h"

void	cr_debug(t_file_pos *file_pos, t_size count, ...)
{
	char	*ret;
	char	*header;
	va_list	ap;
	char	*fmt;
	t_size	i;

	fmt = "\034[1;31m%s\033[0m, \033[1;31m%s\033[0m, \033[1;31m%d\033[0m";
	header = format(fmt, file_pos->file, file_pos->func, file_pos->line);
	print("DEBUG ");
	print("%s\n", header);
	free(header);
	va_start(ap, count);
	ret = NULL;
	i = 0;
	while (i < count)
	{
		ret = va_arg(ap, char *);
		print("%s", ret);
		free(ret);
		i++;
	}
	va_end(ap);
	print("\n");
}
