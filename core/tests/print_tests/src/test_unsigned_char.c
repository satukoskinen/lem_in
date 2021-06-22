#include <stdio.h>
#include <limits.h>
#include "core.h"

void	test_unsigned_char(int use_ftprintf)
{
	int	ret;
	int	i;
	int (*printf_ptr)(const char*, ...);

	if (use_ftprintf)
		printf_ptr = print;
	else
		printf_ptr = printf;

	printf_ptr("----------------------------------------------\n");
	printf_ptr("Basic tests for unsigned char %%hho %%hhu %%hhx %%hhX\n");
	printf_ptr("----------------------------------------------\n");

	unsigned char unsigned_char[4] = { 0, 42, '~', UCHAR_MAX };

	i = 0;
	while (i < 4)
	{
		ret = printf_ptr("7 '%%' '%hho' '%hhu' '%hhx' '%hhX'\n", unsigned_char[i], unsigned_char[i], unsigned_char[i], unsigned_char[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("8 '%%10' '%10hho' '%10hhu' '%10hhx' '%10hhX'\n", unsigned_char[i], unsigned_char[i], unsigned_char[i], unsigned_char[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("9 '%%.10' '%.10hho' '%.10hhu' '%.10hhx' '%.10hhX'\n", unsigned_char[i], unsigned_char[i], unsigned_char[i], unsigned_char[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("10 '%%5.1' '%5.1hho' '%5.1hhu' '%5.1hhx' '%5.1hhX'\n", unsigned_char[i], unsigned_char[i], unsigned_char[i], unsigned_char[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("11 '%%5.0' '%5.0hho' '%5.0hhu' '%5.0hhx' '%5.0hhX'\n", unsigned_char[i], unsigned_char[i], unsigned_char[i], unsigned_char[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("12 '%%010' '%010hho' '%010hhu' '%010hhx' '%010hhX'\n", unsigned_char[i], unsigned_char[i], unsigned_char[i], unsigned_char[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("13 '%%05.0' '%05.0hho' '%05.0hhu' '%05.0hhx' '%05.0hhX'\n", unsigned_char[i], unsigned_char[i], unsigned_char[i], unsigned_char[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("14 '%%01.5' '%01.5hho' '%01.5hhu' '%01.5hhx' '%01.5hhX'\n", unsigned_char[i], unsigned_char[i], unsigned_char[i], unsigned_char[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("15 '%%1.5' '%1.5hho' '%1.5hhu' '%1.5hhx' '%1.5hhX'\n", unsigned_char[i], unsigned_char[i], unsigned_char[i], unsigned_char[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("16 '%%#1.5' '%#1.5hho' '%1.5hhu' '%#1.5hhx' '%#1.5hhX'\n", unsigned_char[i], unsigned_char[i], unsigned_char[i], unsigned_char[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("17 '%%-#1.5' '%-#1.5hho' '%-1.5hhu' '%-#1.5hhx' '%-#1.5hhX'\n", unsigned_char[i], unsigned_char[i], unsigned_char[i], unsigned_char[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("18 '%%-#1.5' '%-#1.5hho' '%-1.5hhu' '%-#1.5hhx' '%-#1.5hhX'\n", unsigned_char[i], unsigned_char[i], unsigned_char[i], unsigned_char[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("19 '%%-1.5' '%#-1.5hho' '%-1.5hhu' '%#-1.5hhx' '%#-1.5hhX'\n", unsigned_char[i], unsigned_char[i], unsigned_char[i], unsigned_char[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("20 '%%#-1.5' '%#-1.5hho' '%-1.5hhu' '%#-1.5hhx' '%#-1.5hhX'\n", unsigned_char[i], unsigned_char[i], unsigned_char[i], unsigned_char[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("21 '%%#-1.0' '%#-1.0hho' '%-1.0hhu' '%#-1.0hhx' '%#-1.0hhX'\n", unsigned_char[i], unsigned_char[i], unsigned_char[i], unsigned_char[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("22 '%%#-10.10' '%#-10.10hho' '%-10.10hhu' '%#-10.10hhx' '%#-10.10hhX'\n", unsigned_char[i], unsigned_char[i], unsigned_char[i], unsigned_char[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("23 '%%#-10' '%#-10hho' '%-10hhu' '%#-10hhx' '%#-10hhX'\n", unsigned_char[i], unsigned_char[i], unsigned_char[i], unsigned_char[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("24 '%%.' '%.hho' '%.hhu' '%.hhx' '%.hhX'\n", unsigned_char[i], unsigned_char[i], unsigned_char[i], unsigned_char[i]);
		printf_ptr("ret is %d\n", ret);

		i++;
	}

	ret = printf_ptr("testing %hho\n", (unsigned char)42);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("print zero '%#hho'\n", (unsigned char)0);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("octal alt form '%#10.5hho'\n", (unsigned char)100);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("octal alt form zero '%#10.8hho'\n", (unsigned char)250);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("octal alt form zero '%#.hho'\n", (unsigned char)250);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("octal alt form zero '%#hho'\n", (unsigned char)250);
	printf_ptr("ret is %d\n", ret);
}