#include "lem_in.h"

static int	save_flag(t_flags *flags, t_flag flag, char **argv, int *i)
{
	if (flag.argument_required && argv[*i + 1] == NULL)
		return (0);
	if (flag.name_short[0] == 'h' && !flags->usage)
		flags->usage = TRUE;
	else if (flag.name_short[0] == 'v' && !flags->verbose)
		flags->verbose = TRUE;
	else if (flag.name_short[0] == 'f' && !flags->read_from_file)
	{
		flags->read_from_file = TRUE;
		flags->file = argv[*i + 1];
		*i = *i + 1;
	}
	else
		return (0);
	*i = *i + 1;
	return (1);
}

static int	parse_option(t_flags *flags, char **argv, int *i)
{
	static const t_flag	options[] = {
		{"help", "h", FALSE},
		{"verbose", "v", FALSE},
		{"file", "f", TRUE},
		{NULL, NULL, 0}
	};
	t_size				j;

	j = 0;
	while (options[j].name_long != NULL)
	{
		if (!s_ncmp(argv[*i], "--", 2)
			&& !s_cmp(&argv[*i][2], options[j].name_long))
			break ;
		else if (!s_cmp(&argv[*i][1], options[j].name_short))
			break ;
		j++;
	}
	if (options[j].name_long == NULL)
		return (0);
	if (!save_flag(flags, options[j], argv, i))
		return (0);
	return (1);
}

int	lem_parse_flags(t_flags *flags, int argc, char **argv)
{
	int	i;
	int	ret;

	mset(flags, 0, sizeof(t_flags));
	if (argc == 1)
		return (1);
	i = 1;
	while (i < argc)
	{
		if (!s_ncmp(argv[i], "--", 2) || !s_ncmp(argv[i], "-", 1))
			ret = parse_option(flags, argv, &i);
		else
			return (0);
		if (ret == 0)
			return (0);
	}
	return (1);
}
