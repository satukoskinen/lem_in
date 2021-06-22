#include <stdio.h>
#include <limits.h>
#include "core.h"

void	test_signed_char(int use_ftprintf)
{
	int			ret;
	int			i;
	int 		(*printf_ptr)(const char*, ...);

	if (use_ftprintf)
			printf_ptr = print;
	else
		printf_ptr = printf;

	printf_ptr("---------------------------------------\n");
	printf_ptr("Bashhic tests for signed char %%hhd %%hhi\n");
	printf_ptr("---------------------------------------\n");

	char	signed_char[] = {0, '~', -10, SCHAR_MAX, SCHAR_MIN};

	i = 0;
	while (i < 4)
	{
		ret = printf_ptr("7 '%%' '%hhd' '%hhi'\n", signed_char[i], signed_char[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("8 '%%10' '%10hhd' '%10hhi'\n", signed_char[i], signed_char[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("9 '%%.10' '%.10hhd' '%.10hhi'\n", signed_char[i], signed_char[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("10 '%%5.1' '%5.1hhd' '%5.1hhi'\n", signed_char[i], signed_char[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("11 '%%5.0' '%5.0hhd' '%5.0hhi'\n", signed_char[i], signed_char[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("12 '%%010' '%010hhd' '%010hhi'\n", signed_char[i], signed_char[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("13 '%%05.0' '%05.0hhd' '%05.0hhi'\n", signed_char[i], signed_char[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("14 '%%01.5' '%01.5hhd' '%01.5hhi'\n", signed_char[i], signed_char[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("15 '%%+1.5' '%+1.5hhd' '%+1.5hhi'\n", signed_char[i], signed_char[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("16 '%%+1.5' '%+1.5hhd' '%+1.5hhi'\n", signed_char[i], signed_char[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("18 '%%-+1.5' '%-+1.5hhd' '%-+1.5hhi'\n", signed_char[i], signed_char[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("19 '%%-+1.5' '%-+1.5hhd' '%-+1.5hhi'\n", signed_char[i], signed_char[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("20 '%% -1.5' '% -1.5hhd' '% -1.5hhi'\n", signed_char[i], signed_char[i]);
		printf_ptr("ret is %d\n", ret);
		
		ret = printf_ptr("21 '%% -1.0' '% -1.0hhd' '% -1.0hhi'\n", signed_char[i], signed_char[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("22 '%% -10.10' '% -10.10hhd' '% -10.10hhi'\n", signed_char[i], signed_char[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("23 '%% -10' '% -10hhd' '% -10hhi'\n", signed_char[i], signed_char[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("24 '%%.' '%.hhd' '%.hhi'\n", signed_char[i], signed_char[i]);
		printf_ptr("ret is %d\n", ret);

		printf_ptr("\n\n\n\n\n\n\n\n");
		i++;
	}

	ret = printf_ptr("1 testhhing %%hhd %%hhi '%hhd' '%hhi'\n", (signed char)42, (signed char)42);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("2 testhhing %%hhd %%hhi '%hhd' '%hhi'\n", (signed char)-42, (signed char)-42);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("3 zeros %%hhd %%hhi '%hhd' '%hhi'\n", (signed char)0, (signed char)0);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("4 testhhing %%+hhi %% hhd '%+hhi' '% hhd'\n", (signed char)2147483647, (signed char)(-2147483647 - 1));
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("5 testhhing %%.1hhd %%+.1hhi %% hhd '%.1hhd' '%+.1hhi' '% hhd'\n", (signed char)42, (signed char)2147483647, (signed char)(-2147483647 - 1));	
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("6a %%-10000.8 '%%10' '%-10000.8hhd'\n", (signed char)-123);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("6b %%-10.8000 '%-10.8000hhd'\n", (signed char)-123);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("6b %%010000.8000 '%010000.8000hhd'\n", (signed char)-123);
	printf_ptr("ret is %d\n", ret);
}
