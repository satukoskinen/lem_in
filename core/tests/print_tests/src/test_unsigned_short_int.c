#include <stdio.h>
#include <limits.h>
#include "core.h"

void	test_unsigned_short_int(int use_ftprintf)
{
	int	ret;
	int	i;
	int (*printf_ptr)(const char*, ...);

	if (use_ftprintf)
		printf_ptr = print;
	else
		printf_ptr = printf;

	printf_ptr("------------------------------------------\n");
	printf_ptr("Basic tests for unsigned short %%ho %%hu %%hx %%hX\n");
	printf_ptr("------------------------------------------\n");

	unsigned short	unsigned_short[3] = { 0, 42, USHRT_MAX };

	i = 0;
	while (i < 3)
	{
		ret = printf_ptr("7 '%%' '%ho' '%hu' '%hx' '%hX'\n", unsigned_short[i], unsigned_short[i], unsigned_short[i], unsigned_short[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("8 '%%10' '%10ho' '%10hu' '%10hx' '%10hX'\n", unsigned_short[i], unsigned_short[i], unsigned_short[i], unsigned_short[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("9 '%%.10' '%.10ho' '%.10hu' '%.10hx' '%.10hX'\n", unsigned_short[i], unsigned_short[i], unsigned_short[i], unsigned_short[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("10 '%%5.1' '%5.1ho' '%5.1hu' '%5.1hx' '%5.1hX'\n", unsigned_short[i], unsigned_short[i], unsigned_short[i], unsigned_short[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("11 '%%5.0' '%5.0ho' '%5.0hu' '%5.0hx' '%5.0hX'\n", unsigned_short[i], unsigned_short[i], unsigned_short[i], unsigned_short[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("12 '%%010' '%010ho' '%010hu' '%010hx' '%010hX'\n", unsigned_short[i], unsigned_short[i], unsigned_short[i], unsigned_short[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("13 '%%05.0' '%05.0ho' '%05.0hu' '%05.0hx' '%05.0hX'\n", unsigned_short[i], unsigned_short[i], unsigned_short[i], unsigned_short[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("14 '%%01.5' '%01.5ho' '%01.5hu' '%01.5hx' '%01.5hX'\n", unsigned_short[i], unsigned_short[i], unsigned_short[i], unsigned_short[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("15 '%%1.5' '%1.5ho' '%1.5hu' '%1.5hx' '%1.5hX'\n", unsigned_short[i], unsigned_short[i], unsigned_short[i], unsigned_short[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("16 '%%#1.5' '%#1.5ho' '%1.5hu' '%#1.5hx' '%#1.5hX'\n", unsigned_short[i], unsigned_short[i], unsigned_short[i], unsigned_short[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("17 '%%-#1.5' '%-#1.5ho' '%-1.5hu' '%-#1.5hx' '%-#1.5hX'\n", unsigned_short[i], unsigned_short[i], unsigned_short[i], unsigned_short[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("18 '%%-#1.5' '%-#1.5ho' '%-1.5hu' '%-#1.5hx' '%-#1.5hX'\n", unsigned_short[i], unsigned_short[i], unsigned_short[i], unsigned_short[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("19 '%%-1.5' '%#-1.5ho' '%-1.5hu' '%#-1.5hx' '%#-1.5hX'\n", unsigned_short[i], unsigned_short[i], unsigned_short[i], unsigned_short[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("20 '%%#-1.5' '%#-1.5ho' '%-1.5hu' '%#-1.5hx' '%#-1.5hX'\n", unsigned_short[i], unsigned_short[i], unsigned_short[i], unsigned_short[i]);
		printf_ptr("ret is %d\n", ret);
	
		ret = printf_ptr("21 '%%#-1.0' '%#-1.0ho' '%-1.0hu' '%#-1.0hx' '%#-1.0hX'\n", unsigned_short[i], unsigned_short[i], unsigned_short[i], unsigned_short[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("22 '%%#-10.10' '%#-10.10ho' '%-10.10hu' '%#-10.10hx' '%#-10.10hX'\n", unsigned_short[i], unsigned_short[i], 	unsigned_short[i], unsigned_short[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("23 '%%#-10' '%#-10ho' '%-10hu' '%#-10hx' '%#-10hX'\n", unsigned_short[i], unsigned_short[i], unsigned_short[i], unsigned_short[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("24 '%%.' '%.ho' '%.hu' '%.hx' '%.hX'\n", unsigned_short[i], unsigned_short[i], unsigned_short[i], unsigned_short[i]);
		printf_ptr("ret is %d\n", ret);

		i++;
	}

	ret = printf_ptr("testing %ho\n", (unsigned short)42);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("print zerho '%#ho'\n", (unsigned short)0);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("octal alt form '%#10.5ho'\n", (unsigned short)123423);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("octal alt form zerho '%#10.8ho'\n", (unsigned short)123423);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("octal alt form zerho '%#.ho'\n", (unsigned short)123423);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("octal alt form zerho '%#ho'\n", (unsigned short)123423);
	printf_ptr("ret is %d\n", ret);
}