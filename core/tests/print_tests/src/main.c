#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "core.h"
#include "tests.h"

int		main(int argc, char **argv)
{
	int		use_ftprintf;

	if (argc > 1 && strcmp(argv[1], "printf") == 0)
		use_ftprintf = 0;
	else
		use_ftprintf = 1;
	if (argc == 1 || (argc > 2 && strcmp(argv[2], "test_all") == 0))
	{
		test_char(use_ftprintf);
		test_string(use_ftprintf);
		test_pointer();
		test_int(use_ftprintf);
		test_signed_char(use_ftprintf);
		test_short_int(use_ftprintf);
		test_long_int(use_ftprintf);
		test_long_long_int(use_ftprintf);
		test_unsigned_int(use_ftprintf);
		test_unsigned_char(use_ftprintf);
		test_unsigned_short_int(use_ftprintf);
		test_unsigned_long_int(use_ftprintf);
		test_unsigned_long_long_int(use_ftprintf);
		test_double(use_ftprintf);
		test_long_double(use_ftprintf);
	}
	else if (strcmp(argv[2], "test_char") == 0)
		test_char(use_ftprintf);
	else if (strcmp(argv[2], "test_string") == 0)
		test_string(use_ftprintf);
	else if (strcmp(argv[2], "test_pointer") == 0)
		test_pointer();
	else if (strcmp(argv[2], "test_int") == 0)
		test_int(use_ftprintf);
	else if (strcmp(argv[2], "test_signed_char") == 0)
		test_signed_char(use_ftprintf);
	else if (strcmp(argv[2], "test_short_int") == 0)
		test_short_int(use_ftprintf);
	else if (strcmp(argv[2], "test_long_int") == 0)
		test_long_int(use_ftprintf);
	else if (strcmp(argv[2], "test_long_long_int") == 0)
		test_long_long_int(use_ftprintf);
	else if (strcmp(argv[2], "test_unsigned_int") == 0)
		test_unsigned_int(use_ftprintf);
	else if (strcmp(argv[2], "test_unsigned_char") == 0)
		test_unsigned_char(use_ftprintf);
	else if (strcmp(argv[2], "test_unsigned_short_int") == 0)
		test_unsigned_short_int(use_ftprintf);
	else if (strcmp(argv[2], "test_unsigned_long_int") == 0)
		test_unsigned_long_int(use_ftprintf);
	else if (strcmp(argv[2], "test_unsigned_long_long_int") == 0)
		test_unsigned_long_long_int(use_ftprintf);
	else if (strcmp(argv[2], "test_double") == 0)
		test_double(use_ftprintf);
	else if (strcmp(argv[2], "test_long_double") == 0)
		test_long_double(use_ftprintf);

	if (argc > 1 && strcmp(argv[argc - 1], "valgrind") == 0)
		system("valgrind --leak-check=full ./test_exe print all");
	if (argc > 1 && strcmp(argv[argc - 1], "leaks") == 0)
		system("leaks test_exe");
	return (0);
}
