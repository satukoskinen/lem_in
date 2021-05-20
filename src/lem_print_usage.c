#include "lem_in.h"

int	lem_print_usage(void)
{
	static const char	*usage = "\
usage: ./lem-in [--help] [--verbose] [--file input_file | < input_file]\n\
\n\
  -h, --help			print usage\n\
  -v, --verbose			verbose mode\n\
  -f, --file input_file		read input from input_file instead of stdin\n\
\n\
input_file must be of the format\n\
  number_of_ants\n\
  rooms\n\
  links\n\
where each room is defined by 'name coord_x coord_y' and each link by 'name1-name2',\n\
source node is preceded by command '##start' and target node by '##end'\n\
(see lem-in.en.pdf for more information)\n";

	print("%s", usage);
	return (0);
}
