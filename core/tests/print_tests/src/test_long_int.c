#include <stdio.h>
#include <limits.h>
#include "core.h"

void	test_long_int(int use_ftprintf)
{
	int			ret;
	int			i;
	int 		(*printf_ptr)(const char*, ...);

	if (use_ftprintf)
			printf_ptr = print;
	else
		printf_ptr = printf;

	printf_ptr("---------------------------------------\n");
	printf_ptr("Baslic tests for long %%ld %%li\n");
	printf_ptr("---------------------------------------\n");

	long	signed_long[] = {0, 42, -10, LONG_MAX, LONG_MIN};

	i = 0;
	while (i < 4)
	{
		ret = printf_ptr("7 '%%' '%ld' '%li'\n", signed_long[i], signed_long[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("8 '%%10' '%10ld' '%10li'\n", signed_long[i], signed_long[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("9 '%%.10' '%.10ld' '%.10li'\n", signed_long[i], signed_long[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("10 '%%5.1' '%5.1ld' '%5.1li'\n", signed_long[i], signed_long[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("11 '%%5.0' '%5.0ld' '%5.0li'\n", signed_long[i], signed_long[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("12 '%%010' '%010ld' '%010li'\n", signed_long[i], signed_long[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("13 '%%05.0' '%05.0ld' '%05.0li'\n", signed_long[i], signed_long[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("14 '%%01.5' '%01.5ld' '%01.5li'\n", signed_long[i], signed_long[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("15 '%%+1.5' '%+1.5ld' '%+1.5li'\n", signed_long[i], signed_long[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("16 '%%+1.5' '%+1.5ld' '%+1.5li'\n", signed_long[i], signed_long[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("18 '%%-+1.5' '%-+1.5ld' '%-+1.5li'\n", signed_long[i], signed_long[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("19 '%%-+1.5' '%-+1.5ld' '%-+1.5li'\n", signed_long[i], signed_long[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("20 '%% -1.5' '% -1.5ld' '% -1.5li'\n", signed_long[i], signed_long[i]);
		printf_ptr("ret is %d\n", ret);
		
		ret = printf_ptr("21 '%% -1.0' '% -1.0ld' '% -1.0li'\n", signed_long[i], signed_long[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("22 '%% -10.10' '% -10.10ld' '% -10.10li'\n", signed_long[i], signed_long[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("23 '%% -10' '% -10ld' '% -10li'\n", signed_long[i], signed_long[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("24 '%%.' '%.ld' '%.li'\n", signed_long[i], signed_long[i]);
		printf_ptr("ret is %d\n", ret);

		printf_ptr("\n\n\n\n\n\n\n\n");
		i++;
	}

	ret = printf_ptr("1 testling %%ld %%li '%ld' '%li'\n", (long)42, (long)42);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("2 testling %%ld %%li '%ld' '%li'\n", (long)-42, (long)-42);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("3 zeros %%ld %%li '%ld' '%li'\n", (long)0, (long)0);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("4 testling %%+li %% ld '%+li' '% ld'\n", (long)2147483647, (long)(-2147483647 - 1));
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("5 testling %%.1ld %%+.1li %% ld '%.1ld' '%+.1li' '% ld'\n", (long)42, (long)2147483647, (long)(-2147483647 - 1));
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("6a %%-10000.8 '%%10' '%-10000.8ld'\n", (long)-123423);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("6b %%-10.8000 '%-10.8000ld'\n", (long)-123423);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("6b %%010000.8000 '%010000.8000ld'\n", (long)-123423);
	printf_ptr("ret is %d\n", ret);
}
