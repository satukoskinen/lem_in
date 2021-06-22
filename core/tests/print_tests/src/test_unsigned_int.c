#include <stdio.h>
#include <limits.h>
#include "core.h"

void	test_unsigned_int(int use_ftprintf)
{
	int	ret;
	int	i;
	int (*printf_ptr)(const char*, ...);

	if (use_ftprintf)
		printf_ptr = print;
	else
		printf_ptr = printf;

	printf_ptr("---------------------------------------\n");
	printf_ptr("Basic tests for unsigned int %%o %%u %%x %%X\n");
	printf_ptr("---------------------------------------\n");

	unsigned int unsigned_int[3] = { 0, 392082, UINT_MAX };

	i = 0;
	while (i < 3)
	{
		ret = printf_ptr("7 '%%' '%o' '%u' '%x' '%X'\n", unsigned_int[i], unsigned_int[i], unsigned_int[i], unsigned_int[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("8 '%%10' '%10o' '%10u' '%10x' '%10X'\n", unsigned_int[i], unsigned_int[i], unsigned_int[i], unsigned_int[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("9 '%%.10' '%.10o' '%.10u' '%.10x' '%.10X'\n", unsigned_int[i], unsigned_int[i], unsigned_int[i], unsigned_int[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("10 '%%5.1' '%5.1o' '%5.1u' '%5.1x' '%5.1X'\n", unsigned_int[i], unsigned_int[i], unsigned_int[i], unsigned_int[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("11 '%%5.0' '%5.0o' '%5.0u' '%5.0x' '%5.0X'\n", unsigned_int[i], unsigned_int[i], unsigned_int[i], unsigned_int[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("12 '%%010' '%010o' '%010u' '%010x' '%010X'\n", unsigned_int[i], unsigned_int[i], unsigned_int[i], unsigned_int[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("13 '%%05.0' '%05.0o' '%05.0u' '%05.0x' '%05.0X'\n", unsigned_int[i], unsigned_int[i], unsigned_int[i], unsigned_int[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("14 '%%01.5' '%01.5o' '%01.5u' '%01.5x' '%01.5X'\n", unsigned_int[i], unsigned_int[i], unsigned_int[i], unsigned_int[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("15 '%%1.5' '%1.5o' '%1.5u' '%1.5x' '%1.5X'\n", unsigned_int[i], unsigned_int[i], unsigned_int[i], unsigned_int[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("16 '%%#1.5' '%#1.5o' '%1.5u' '%#1.5x' '%#1.5X'\n", unsigned_int[i], unsigned_int[i], unsigned_int[i], unsigned_int[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("17 '%%-#1.5' '%-#1.5o' '%-1.5u' '%-#1.5x' '%-#1.5X'\n", unsigned_int[i], unsigned_int[i], unsigned_int[i], unsigned_int[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("18 '%%-#1.5' '%-#1.5o' '%-1.5u' '%-#1.5x' '%-#1.5X'\n", unsigned_int[i], unsigned_int[i], unsigned_int[i], unsigned_int[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("19 '%%-1.5' '%#-1.5o' '%-1.5u' '%#-1.5x' '%#-1.5X'\n", unsigned_int[i], unsigned_int[i], unsigned_int[i], unsigned_int[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("20 '%%#-1.5' '%#-1.5o' '%-1.5u' '%#-1.5x' '%#-1.5X'\n", unsigned_int[i], unsigned_int[i], unsigned_int[i], unsigned_int[i]);
		printf_ptr("ret is %d\n", ret);
		
		ret = printf_ptr("21 '%%#-1.0' '%#-1.0o' '%-1.0u' '%#-1.0x' '%#-1.0X'\n", unsigned_int[i], unsigned_int[i], unsigned_int[i], unsigned_int[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("22 '%%#-10.10' '%#-10.10o' '%-10.10u' '%#-10.10x' '%#-10.10X'\n", unsigned_int[i], unsigned_int[i], unsigned_int[i], unsigned_int[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("23 '%%#-10' '%#-10o' '%-10u' '%#-10x' '%#-10X'\n", unsigned_int[i], unsigned_int[i], unsigned_int[i], unsigned_int[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("24 '%%.' '%.o' '%.u' '%.x' '%.X'\n", unsigned_int[i], unsigned_int[i], unsigned_int[i], unsigned_int[i]);
		printf_ptr("ret is %d\n", ret);

		i++;
	}

	ret = printf_ptr("testing %o\n", 42);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("print zero '%#o'\n", 0);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("octal alt form '%#10.5o'\n",123423);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("octal alt form zero '%#10.8o'\n",123423);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("octal alt form zero '%#.o'\n",123423);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("octal alt form zero '%#o'\n",123423);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("print zero '%#x' '%#X'\n", 0, 0);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("print zero '%#-5.x' '%#-5.X'\n", 0, 0);
	printf_ptr("ret is %d\n", ret);
}