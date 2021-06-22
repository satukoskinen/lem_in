#include <stdio.h>
#include <limits.h>
#include "core.h"

void	test_unsigned_long_long_int(int use_ftprintf)
{
	int	ret;
	int	i;
	int (*printf_ptr)(const char*, ...);

	if (use_ftprintf)
		printf_ptr = print;
	else
		printf_ptr = printf;

	printf_ptr("------------------------------------------\n");
	printf_ptr("Basic tests for unsigned long long %%llo %%llu %%llx %%llX\n");
	printf_ptr("------------------------------------------\n");

	unsigned long long unsigned_long_long[3] = { 0, 392082, ULLONG_MAX };

	i = 0;
	while (i < 3)
	{
		ret = printf_ptr("7 '%%' '%llo' '%llu' '%llx' '%llX'\n", unsigned_long_long[i], unsigned_long_long[i], unsigned_long_long[i], unsigned_long_long[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("8 '%%10' '%10llo' '%10llu' '%10llx' '%10llX'\n", unsigned_long_long[i], unsigned_long_long[i], unsigned_long_long[i], unsigned_long_long[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("9 '%%.10' '%.10llo' '%.10llu' '%.10llx' '%.10llX'\n", unsigned_long_long[i], unsigned_long_long[i], unsigned_long_long[i], unsigned_long_long[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("10 '%%5.1' '%5.1llo' '%5.1llu' '%5.1llx' '%5.1llX'\n", unsigned_long_long[i], unsigned_long_long[i], unsigned_long_long[i], unsigned_long_long[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("11 '%%5.0' '%5.0llo' '%5.0llu' '%5.0llx' '%5.0llX'\n", unsigned_long_long[i], unsigned_long_long[i], unsigned_long_long[i], unsigned_long_long[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("12 '%%010' '%010llo' '%010llu' '%010llx' '%010llX'\n", unsigned_long_long[i], unsigned_long_long[i], unsigned_long_long[i], unsigned_long_long[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("13 '%%05.0' '%05.0llo' '%05.0llu' '%05.0llx' '%05.0llX'\n", unsigned_long_long[i], unsigned_long_long[i], unsigned_long_long[i], unsigned_long_long[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("14 '%%01.5' '%01.5llo' '%01.5llu' '%01.5llx' '%01.5llX'\n", unsigned_long_long[i], unsigned_long_long[i], unsigned_long_long[i], unsigned_long_long[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("15 '%%1.5' '%1.5llo' '%1.5llu' '%1.5llx' '%1.5llX'\n", unsigned_long_long[i], unsigned_long_long[i], unsigned_long_long[i], unsigned_long_long[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("16 '%%#1.5' '%#1.5llo' '%1.5llu' '%#1.5llx' '%#1.5llX'\n", unsigned_long_long[i], unsigned_long_long[i], unsigned_long_long[i], unsigned_long_long[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("17 '%%-#1.5' '%-#1.5llo' '%-1.5llu' '%-#1.5llx' '%-#1.5llX'\n", unsigned_long_long[i], unsigned_long_long[i], unsigned_long_long[i], unsigned_long_long[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("18 '%%-#1.5' '%-#1.5llo' '%-1.5llu' '%-#1.5llx' '%-#1.5llX'\n", unsigned_long_long[i], unsigned_long_long[i], unsigned_long_long[i], unsigned_long_long[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("19 '%%-1.5' '%#-1.5llo' '%-1.5llu' '%#-1.5llx' '%#-1.5llX'\n", unsigned_long_long[i], unsigned_long_long[i], unsigned_long_long[i], unsigned_long_long[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("20 '%%#-1.5' '%#-1.5llo' '%-1.5llu' '%#-1.5llx' '%#-1.5llX'\n", unsigned_long_long[i], unsigned_long_long[i], unsigned_long_long[i], unsigned_long_long[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("21 '%%#-1.0' '%#-1.0llo' '%-1.0llu' '%#-1.0llx' '%#-1.0llX'\n", unsigned_long_long[i], unsigned_long_long[i], unsigned_long_long[i], unsigned_long_long[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("22 '%%#-10.10' '%#-10.10llo' '%-10.10llu' '%#-10.10llx' '%#-10.10llX'\n", unsigned_long_long[i], unsigned_long_long[i], unsigned_long_long[i], unsigned_long_long[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("23 '%%#-10' '%#-10llo' '%-10llu' '%#-10llx' '%#-10llX'\n", unsigned_long_long[i], unsigned_long_long[i], unsigned_long_long[i], unsigned_long_long[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("24 '%%.' '%.llo' '%.llu' '%.llx' '%.llX'\n", unsigned_long_long[i], unsigned_long_long[i], unsigned_long_long[i], unsigned_long_long[i]);
		printf_ptr("ret is %d\n", ret);

		i++;
	}

	ret = printf_ptr("testing %llo\n", (unsigned long long)42);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("print zerllo '%#llo'\n", (unsigned long long)0);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("octall allt form '%#10.5llo'\n", (unsigned long long)123423);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("octall allt form zerllo '%#10.8llo'\n", (unsigned long long)123423);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("octall allt form zerllo '%#.llo'\n", (unsigned long long)123423);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("octall allt form zerllo '%#llo'\n", (unsigned long long)123423);
	printf_ptr("ret is %d\n", ret);
}