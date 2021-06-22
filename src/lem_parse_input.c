#include "lem_in.h"

/*
 *	Parse the ant count received as the first line of input
 *	from stdin. If it is invalid, negative or contains non-digit
 *	characters, return an error.
 */

static int	parse_ant_count(t_parray *input, int fd)
{
	char	*line;
	int		ret;
	int		ant_count;
	t_size	i;

	line = NULL;
	ret = s_readline(fd, &line);
	if (ret != 1)
		return (-1);
	ant_count = a_to_i(line);
	i = 0;
	while (is_digit(line[i]))
		i++;
	if (line[i] != '\0')
	{
		free(line);
		return (-1);
	}
	if (!parr_add_last(input, line))
	{
		free(line);
		return (-1);
	}
	return (ant_count);
}

/*
 *	First parse ant count, then rooms and links one line at a time.
 *	If the ant count is invalid, an error occurs during parsing lines,
 *	or a source or a sink node has not been saved, return an error.
 */

int	lem_parse_input(t_lem *data, t_parray *input, t_flags flags)
{
	int					fd;
	int					ant_count;
	int					ret;
	enum e_line_type	type;

	if (flags.read_from_file)
		fd = open(flags.file, O_RDONLY);
	else
		fd = 0;
	if (fd == -1)
		return (-1);
	ant_count = parse_ant_count(input, fd);
	if (ant_count < 0)
		return (-1);
	data->ant_count = (t_size)ant_count;
	type = ROOM;
	ret = 1;
	while (ret == 1)
		ret = lem_parse_line(data, input, fd, &type);
	if (ret == -1)
		return (-1);
	if (data->s_key == NULL || data->t_key == NULL)
		return (-1);
	return (1);
}
