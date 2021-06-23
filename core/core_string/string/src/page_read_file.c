#include "../inc/string.h"

t_ssize	page_read_file(t_page *dst, char *filename)
{
	char	*line;
	t_str	string;
	t_ssize	fd;
	t_ssize	ret;

	if (filename == NULL)
		return (CR_FAIL);
	fd = open(filename, O_RDONLY);
	if (!fd)
		return (CR_FAIL);
	line = NULL;
	ret = 1;
	while (ret == 1)
	{
		ret = s_readline(fd, &line);
		string = str_from_s(line);
		free(line);
		if (!(arr_add_last(dst, &string)))
			return (CR_FAIL);
	}
	close(fd);
	if (ret == -1)
		return (-1);
	return (dst->len);
}
