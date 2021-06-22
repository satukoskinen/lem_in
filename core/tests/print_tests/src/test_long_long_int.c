#include <stdio.h>
#include <limits.h>
#include "core.h"

void	test_long_long_int(int use_ftprintf)
{
	int			ret;
	int			i;
	int 		(*printf_ptr)(const char*, ...);

	if (use_ftprintf)
			printf_ptr = print;
	else
		printf_ptr = printf;

	printf_ptr("---------------------------------------\n");
	printf_ptr("Basic tests for long long %%lld %%lli\n");
	printf_ptr("---------------------------------------\n");

	long long	signed_long_long[] = {0, 42, -10, LLONG_MAX, LLONG_MIN};

	i = 0;
	while (i < 4)
	{
		ret = printf_ptr("7 '%%' '%lld' '%lli'\n", signed_long_long[i], signed_long_long[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("8 '%%10' '%10lld' '%10lli'\n", signed_long_long[i], signed_long_long[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("9 '%%.10' '%.10lld' '%.10lli'\n", signed_long_long[i], signed_long_long[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("10 '%%5.1' '%5.1lld' '%5.1lli'\n", signed_long_long[i], signed_long_long[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("11 '%%5.0' '%5.0lld' '%5.0lli'\n", signed_long_long[i], signed_long_long[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("12 '%%010' '%010lld' '%010lli'\n", signed_long_long[i], signed_long_long[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("13 '%%05.0' '%05.0lld' '%05.0lli'\n", signed_long_long[i], signed_long_long[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("14 '%%01.5' '%01.5lld' '%01.5lli'\n", signed_long_long[i], signed_long_long[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("15 '%%+1.5' '%+1.5lld' '%+1.5lli'\n", signed_long_long[i], signed_long_long[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("16 '%%+1.5' '%+1.5lld' '%+1.5lli'\n", signed_long_long[i], signed_long_long[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("18 '%%-+1.5' '%-+1.5lld' '%-+1.5lli'\n", signed_long_long[i], signed_long_long[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("19 '%%-+1.5' '%-+1.5lld' '%-+1.5lli'\n", signed_long_long[i], signed_long_long[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("20 '%% -1.5' '% -1.5lld' '% -1.5lli'\n", signed_long_long[i], signed_long_long[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("21 '%% -1.0' '% -1.0lld' '% -1.0lli'\n", signed_long_long[i], signed_long_long[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("22 '%% -10.10' '% -10.10lld' '% -10.10lli'\n", signed_long_long[i], signed_long_long[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("23 '%% -10' '% -10lld' '% -10lli'\n", signed_long_long[i], signed_long_long[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("24 '%%.' '%.lld' '%.lli'\n", signed_long_long[i], signed_long_long[i]);
		printf_ptr("ret is %d\n", ret);

		printf_ptr("\n\n\n\n\n\n\n\n");
		i++;
	}

	ret = printf_ptr("1 testlling %%lld %%lli '%lld' '%lli'\n", (long long)42, (long long)42);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("2 testlling %%lld %%lli '%lld' '%lli'\n", (long long)-42, (long long)-42);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("3 zeros %%lld %%lli '%lld' '%lli'\n", (long long)0, (long long)0);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("4 testlling %%+lli %% lld '%+lli' '% lld'\n", (long long)2147483647, (long long)(-2147483647 - 1));
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("5 testlling %%.1lld %%+.1lli %% lld '%.1lld' '%+.1lli' '% lld'\n", (long long)42, (long long)2147483647, (long long)(-2147483647 - 1));
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("6a %%-10000.8 '%%10' '%-10000.8lld'\n", (long long)-123423);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("6b %%-10.8000 '%-10.8000lld'\n", (long long)-123423);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("6b %%010000.8000 '%010000.8000lld'\n", (long long)-123423);
	printf_ptr("ret is %d\n", ret);
}
