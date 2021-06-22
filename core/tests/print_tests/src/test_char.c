#include <stdio.h>
#include <string.h>
#include "core.h"

void	test_char(int use_ftprintf)
{
	int		ret;
	int 	(*printf_ptr)(const char*, ...);

	if (use_ftprintf)
		printf_ptr = print;
	else
		printf_ptr = printf;

	printf_ptr("---------------------------\n");
	printf_ptr("Basic tests for %%c\n");
	printf_ptr("---------------------------\n");

	ret = printf_ptr("print null character '%c'\n", '\0');
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("character tests: '%c' '%c' '%c' '%c' '%c' '%c' '%c' '%c' '%c' '%c' '%c' '%c' '%c' '%c' '%c' '%c' '%c' '%c' '%c' '%c'\n", 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't');
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("character tests: '%c' '%c' '%c' '%c' '%c' '%c' '%c' '%c' '%c' '%c' '%c' '%c' '%c' '%c' '%c' '%c' '%c' '%c' '%c' '%c'\n", '1', '2', '3', '4', '5', '0', '*', '%', ' ', '\t', '\n', '-', 0, 47, 126, 125, 124, 123, 33, 34);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("print character '%10c'\n", '*');
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("print character '%-10c'\n", '*');
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("char '%-100c'\n", 'c');
	printf_ptr("ret is %d\n", ret);
}