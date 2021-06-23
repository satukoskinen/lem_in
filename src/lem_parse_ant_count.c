#include "lem_in.h"

static int	parse_comment_or_command(int fd, char **line, t_parray *input)
{
	int	ret;

	ret = 1;
	while (ret == 1 && s_ncmp("#", *line, 1) == 0)
	{
		if (s_ncmp("##", *line, 2) == 0
			&& (s_cmp("##start", *line) == 0 || s_cmp("##end", *line) == 0))
		{
			free(*line);
			return (-1);
		}
		if (!parr_add_last(input, *line))
		{
			free(*line);
			return (-1);
		}
		ret = s_readline(fd, line);
	}
	return (ret);
}

/*
 *	Parse the ant count received as the first line of input
 *	from stdin. If it is invalid, negative or contains non-digit
 *	characters, return an error.
 */

int	parse_ant_count(t_parray *input, int fd)
{
	char	*line;
	int		ret;
	int		ant_count;
	t_size	i;

	line = NULL;
	ret = s_readline(fd, &line);
	if (ret == 1 && s_ncmp("#", line, 1) == 0)
		ret = parse_comment_or_command(fd, &line, input);
	if (ret != 1)
		return (-1);
	ant_count = a_to_i(line);
	i = 0;
	while (is_digit(line[i]))
		i++;
	if (line[i] != '\0' || !parr_add_last(input, line))
	{
		free(line);
		return (-1);
	}
	return (ant_count);
}
