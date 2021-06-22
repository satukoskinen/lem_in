#include <stdio.h>
#include <limits.h>
#include "core.h"

void	test_short_int(int use_ftprintf)
{
	int			ret;
	int			i;
	int 		(*printf_ptr)(const char*, ...);

	if (use_ftprintf)
			printf_ptr = print;
	else
		printf_ptr = printf;

	printf_ptr("--------------------------------\n");
	printf_ptr("Bashic tests for short %%hd %%hi\n");
	printf_ptr("--------------------------------\n");

	short	signed_short[] = {0, 42, -10, SHRT_MAX, SHRT_MIN};
	i = 0;

	while (i < 4)
	{
		ret = printf_ptr("7 '%%' '%hd' '%hi'\n", signed_short[i], signed_short[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("8 '%%10' '%10hd' '%10hi'\n", signed_short[i], signed_short[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("9 '%%.10' '%.10hd' '%.10hi'\n", signed_short[i], signed_short[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("10 '%%5.1' '%5.1hd' '%5.1hi'\n", signed_short[i], signed_short[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("11 '%%5.0' '%5.0hd' '%5.0hi'\n", signed_short[i], signed_short[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("12 '%%010' '%010hd' '%010hi'\n", signed_short[i], signed_short[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("13 '%%05.0' '%05.0hd' '%05.0hi'\n", signed_short[i], signed_short[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("14 '%%01.5' '%01.5hd' '%01.5hi'\n", signed_short[i], signed_short[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("15 '%%+1.5' '%+1.5hd' '%+1.5hi'\n", signed_short[i], signed_short[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("16 '%%+1.5' '%+1.5hd' '%+1.5hi'\n", signed_short[i], signed_short[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("18 '%%-+1.5' '%-+1.5hd' '%-+1.5hi'\n", signed_short[i], signed_short[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("19 '%%-+1.5' '%-+1.5hd' '%-+1.5hi'\n", signed_short[i], signed_short[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("20 '%% -1.5' '% -1.5hd' '% -1.5hi'\n", signed_short[i], signed_short[i]);
		printf_ptr("ret is %d\n", ret);
		
		ret = printf_ptr("21 '%% -1.0' '% -1.0hd' '% -1.0hi'\n", signed_short[i], signed_short[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("22 '%% -10.10' '% -10.10hd' '% -10.10hi'\n", signed_short[i], signed_short[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("23 '%% -10' '% -10hd' '% -10hi'\n", signed_short[i], signed_short[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("24 '%%.' '%.hd' '%.hi'\n", signed_short[i], signed_short[i]);
		printf_ptr("ret is %d\n", ret);

		printf_ptr("\n\n\n\n\n\n\n\n");
		i++;
	}

	ret = printf_ptr("1 testhing %%hd %%hi '%hd' '%hi'\n", (short)42, (short)42);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("2 testhing %%hd %%hi '%hd' '%hi'\n", (short)-42, (short)-42);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("3 zeros %%hd %%hi '%hd' '%hi'\n", (short)0, (short)0);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("4 testhing %%+hi %% hd '%+hi' '% hd'\n", (short)2147483647, (short)(-2147483647 - 1));
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("5 testhing %%.1hd %%+.1hi %% hd '%.1hd' '%+.1hi' '% hd'\n", (short)42, (short)2147483647, (short)(-2147483647 - 1));
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("6a %%-10000.8 '%%10' '%-10000.8hd'\n", (short)-12423);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("6b %%-10.8000 '%-10.8000hd'\n", (short)-12323);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("6b %%010000.8000 '%010000.8000hd'\n", (short)-12343);
	printf_ptr("ret is %d\n", ret);
}
