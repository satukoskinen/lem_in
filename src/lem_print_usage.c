#include "lem-in.h"

int	lem_print_usage(void)
{
	static const char	*usage = "\n\
usage: ./lem-in [--help] [--verbose] [--file input_file | < input_file]\n\n\
  -h, --help			print usage\n\
  -v, --verbose			verbose mode\n\
  -f, --file input_file		read input from input_file instead of stdin\n\n";

	print("%s", usage);
	return (0);
}
