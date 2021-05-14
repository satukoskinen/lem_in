#include "lem-in.h"

static int	parse_ant_count(t_parray *input)
{
	char	*line;
	int		ret;
	int		ant_count;

	line = NULL;
	ret = s_readline(0, &line);
	if (ret != 1)
		return (-1);
	ant_count = a_to_i(line);
	if (ant_count == 0 && line[0] != '0')
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

int	lem_parse_input(t_lem *data, t_parray *input)
{
	int					ant_count;
	int					ret;
	enum e_line_type	type;

	ant_count = parse_ant_count(input);
	if (ant_count == -1)
		return (-1);
	data->ant_count = (size_t)ant_count;
	type = ROOM;
	ret = 1;
	while (ret == 1)
		ret = lem_parse_line(data, input, &type);
	if (ret == -1)
		return (-1);
	if (data->s_key == NULL || data->t_key == NULL)
		return (-1);
	return (1);
}
