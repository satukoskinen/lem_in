#include <stdio.h>
#include <limits.h>
#include "core.h"

void	test_unsigned_long_int(int use_ftprintf)
{
	int	ret;
	int	i;
	int (*printf_ptr)(const char*, ...);

	if (use_ftprintf)
		printf_ptr = print;
	else
		printf_ptr = printf;

	printf_ptr("------------------------------------------\n");
	printf_ptr("Basic tests for unsigned long %%lo %%lu %%lx %%lX\n");
	printf_ptr("------------------------------------------\n");
	
	unsigned long unsigned_long[3] = { 0, 392082, ULONG_MAX };

	i = 0;
	while (i < 3)
	{
		ret = printf_ptr("7 '%%' '%lo' '%lu' '%lx' '%lX'\n", unsigned_long[i], unsigned_long[i], unsigned_long[i], unsigned_long[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("8 '%%10' '%10lo' '%10lu' '%10lx' '%10lX'\n", unsigned_long[i], unsigned_long[i], unsigned_long[i], unsigned_long[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("9 '%%.10' '%.10lo' '%.10lu' '%.10lx' '%.10lX'\n", unsigned_long[i], unsigned_long[i], unsigned_long[i], unsigned_long[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("10 '%%5.1' '%5.1lo' '%5.1lu' '%5.1lx' '%5.1lX'\n", unsigned_long[i], unsigned_long[i], unsigned_long[i], unsigned_long[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("11 '%%5.0' '%5.0lo' '%5.0lu' '%5.0lx' '%5.0lX'\n", unsigned_long[i], unsigned_long[i], unsigned_long[i], unsigned_long[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("12 '%%010' '%010lo' '%010lu' '%010lx' '%010lX'\n", unsigned_long[i], unsigned_long[i], unsigned_long[i], unsigned_long[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("13 '%%05.0' '%05.0lo' '%05.0lu' '%05.0lx' '%05.0lX'\n", unsigned_long[i], unsigned_long[i], unsigned_long[i], unsigned_long[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("14 '%%01.5' '%01.5lo' '%01.5lu' '%01.5lx' '%01.5lX'\n", unsigned_long[i], unsigned_long[i], unsigned_long[i], unsigned_long[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("15 '%%1.5' '%1.5lo' '%1.5lu' '%1.5lx' '%1.5lX'\n", unsigned_long[i], unsigned_long[i], unsigned_long[i], unsigned_long[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("16 '%%#1.5' '%#1.5lo' '%1.5lu' '%#1.5lx' '%#1.5lX'\n", unsigned_long[i], unsigned_long[i], unsigned_long[i], unsigned_long[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("17 '%%-#1.5' '%-#1.5lo' '%-1.5lu' '%-#1.5lx' '%-#1.5lX'\n", unsigned_long[i], unsigned_long[i], unsigned_long[i], unsigned_long[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("18 '%%-#1.5' '%-#1.5lo' '%-1.5lu' '%-#1.5lx' '%-#1.5lX'\n", unsigned_long[i], unsigned_long[i], unsigned_long[i], unsigned_long[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("19 '%%-1.5' '%#-1.5lo' '%-1.5lu' '%#-1.5lx' '%#-1.5lX'\n", unsigned_long[i], unsigned_long[i], unsigned_long[i], unsigned_long[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("20 '%%#-1.5' '%#-1.5lo' '%-1.5lu' '%#-1.5lx' '%#-1.5lX'\n", unsigned_long[i], unsigned_long[i], unsigned_long[i], unsigned_long[i]);
		printf_ptr("ret is %d\n", ret);
		
		ret = printf_ptr("21 '%%#-1.0' '%#-1.0lo' '%-1.0lu' '%#-1.0lx' '%#-1.0lX'\n", unsigned_long[i], unsigned_long[i], unsigned_long[i], unsigned_long[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("22 '%%#-10.10' '%#-10.10lo' '%-10.10lu' '%#-10.10lx' '%#-10.10lX'\n", unsigned_long[i], unsigned_long[i], unsigned_long[i], unsigned_long[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("23 '%%#-10' '%#-10lo' '%-10lu' '%#-10lx' '%#-10lX'\n", unsigned_long[i], unsigned_long[i], unsigned_long[i], unsigned_long[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("24 '%%.' '%.lo' '%.lu' '%.lx' '%.lX'\n", unsigned_long[i], unsigned_long[i], unsigned_long[i], unsigned_long[i]);
		printf_ptr("ret is %d\n", ret);

		i++;
	}

	ret = printf_ptr("testing %lo\n", (unsigned long)42);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("print zerlo '%#lo'\n", (unsigned long)0);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("octal alt form '%#10.5lo'\n", (unsigned long)123423);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("octal alt form zerlo '%#10.8lo'\n", (unsigned long)123423);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("octal alt form zerlo '%#.lo'\n", (unsigned long)123423);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("octal alt form zerlo '%#lo'\n", (unsigned long)123423);
	printf_ptr("ret is %d\n", ret);
}