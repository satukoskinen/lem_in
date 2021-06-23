#include "../inc/string.h"

static
t_ssize	deallocate_str(void *data, t_size i)
{
	t_str	*string;

	string = data;
	raw_free(&string->raw);
	return (i);
}

static
t_ssize	write_file(FILE *file, t_page *prepend)
{
	t_size	i;
	t_str	*line;

	i = 0;
	while (i < prepend->len)
	{
		line = arr_get(prepend, i);
		if (line)
		{
			if (!(fprintf(file, "%s\n", line->raw.data)))
				return (CR_FAIL);
		}
		i++;
	}
	arr_iter(prepend, deallocate_str);
	return (1);
}

static
FILE	*open_file(char *filename, t_ssize flag)
{
	FILE	*file;

	if (flag == CR_APPEND)
		file = fopen(filename, "a");
	else
		file = fopen(filename, "w");
	return (file);
}

t_ssize	page_write_file(char *dst, t_page *src, t_ssize flag)
{
	FILE		*file;
	t_page		prepend;

	if (arr_null(src))
		return (CR_FAIL);
	prepend = arr_new(src->len, sizeof(t_str));
	if (flag == CR_PREPEND && !(page_read_file(&prepend, dst)))
		return (CR_FAIL);
	file = open_file(dst, flag);
	if (!file)
		return (CR_FAIL);
	if (!(write_file(file, src)))
		return (CR_FAIL);
	if (flag == CR_PREPEND && !(write_file(file, &prepend)))
		return (CR_FAIL);
	arr_free(&prepend);
	if (file)
		fclose(file);
	return (src->len);
}
