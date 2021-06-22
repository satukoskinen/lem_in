#include <stdio.h>
#include <limits.h>
#include "core.h"

void	test_int(int use_ftprintf)
{
	int			ret;
	int			i;
	int 		(*printf_ptr)(const char*, ...);

	if (use_ftprintf)
			printf_ptr = print;
	else
		printf_ptr = printf;

	printf_ptr("---------------------------\n");
	printf_ptr("Basic tests for int %%d %%i\n");
	printf_ptr("---------------------------\n");

	int		signed_int[] = {0, 392082, -392082, INT_MAX, INT_MIN};
	i = 0;

	while (i < 4)
	{
		ret = printf_ptr("7 '%%' '%d' '%i'\n", signed_int[i], signed_int[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("8 '%%10' '%10d' '%10i'\n", signed_int[i], signed_int[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("9 '%%.10' '%.10d' '%.10i'\n", signed_int[i], signed_int[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("10 '%%5.1' '%5.1d' '%5.1i'\n", signed_int[i], signed_int[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("11 '%%5.0' '%5.0d' '%5.0i'\n", signed_int[i], signed_int[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("12 '%%010' '%010d' '%010i'\n", signed_int[i], signed_int[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("13 '%%05.0' '%05.0d' '%05.0i'\n", signed_int[i], signed_int[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("14 '%%01.5' '%01.5d' '%01.5i'\n", signed_int[i], signed_int[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("15 '%%+1.5' '%+1.5d' '%+1.5i'\n", signed_int[i], signed_int[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("16 '%%+1.5' '%+1.5d' '%+1.5i'\n", signed_int[i], signed_int[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("18 '%%-+1.5' '%-+1.5d' '%-+1.5i'\n", signed_int[i], signed_int[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("19 '%%-+1.5' '%-+1.5d' '%-+1.5i'\n", signed_int[i], signed_int[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("20 '%% -1.5' '% -1.5d' '% -1.5i'\n", signed_int[i], signed_int[i]);
		printf_ptr("ret is %d\n", ret);
		
		ret = printf_ptr("21 '%% -1.0' '% -1.0d' '% -1.0i'\n", signed_int[i], signed_int[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("22 '%% -10.10' '% -10.10d' '% -10.10i'\n", signed_int[i], signed_int[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("23 '%% -10' '% -10d' '% -10i'\n", signed_int[i], signed_int[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("24 '%%.' '%.d' '%.i'\n", signed_int[i], signed_int[i]);
		printf_ptr("ret is %d\n", ret);

		printf_ptr("\n\n\n\n\n\n\n\n");
		i++;
	}

	ret = printf_ptr("1 testing %%d %%i '%d' '%i'\n", 42, 42);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("2 testing %%d %%i '%d' '%i'\n", -42, -42);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("3 zeros %%d %%i '%d' '%i'\n", 0, 0);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("4 testing %%+i %% d '%+i' '% d'\n", 2147483647, -2147483647 - 1);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("5 testing %%.1d %%+.1i %% d '%.1d' '%+.1i' '% d'\n", 42, 2147483647, -2147483647 - 1);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("6a %%-10000.8 %-10000.8d'\n", -123423);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("6b %%-10.8000 '%-10.8000d'\n", -123423);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("6b %%010000.8000 '%010000.8000d'\n", -123423);
	printf_ptr("ret is %d\n", ret);
}
