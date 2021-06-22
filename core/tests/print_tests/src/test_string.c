#include <stdio.h>
#include <string.h>
#include "core.h"

void	test_string(int use_ftprintf)
{
	int		ret;
	int 	(*printf_ptr)(const char*, ...);
	char	unterminated_arr[10];

	strncpy(unterminated_arr, "test", 4);

	if (use_ftprintf)
		printf_ptr = print;
	else
		printf_ptr = printf;

	printf_ptr("---------------------------\n");
	printf_ptr("Basic tests for %%s\n");
	printf_ptr("---------------------------\n");

	/* Test format strings without arguments */

	ret = printf_ptr("print without arguments\n");
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("");
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("print percentage: '%%'\n");
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("print percentage: '%-10.10%' and '%05%'\n");
	printf_ptr("ret is %d\n", ret);

	/* Test strings %s */

	ret = printf_ptr("testing string '%s' %%\n", "tester123456789");
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("harder tests for %%.5s: '%.5s' %%s: '%s'\n%s\n%.100s\n", "adfghjklö", "asdfghjklö", "#saldka384972384edslnaclsalkc", "asdfg");
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("testing string '%.5s' %%\n", "tester123456789");
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("testing empty string '%s'\n", "");
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("testing empty string '%10s'\n", "");
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("testing unterm string '%.4s'\n", unterminated_arr);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("testing unterm string '%.0s'\n", unterminated_arr);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("testing unterm string '%5.4s'\n", unterminated_arr);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("testing unterm string '%5.0s'\n", unterminated_arr);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("testing unterm string '%-.4s'\n", unterminated_arr);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("testing unterm string '%-.0s'\n", unterminated_arr);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("testing string '%10.100s'\n", "asfdkoapvifmepcruinuiosnruoawesrxuesxs");
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("testing string '%100.10s'\n", "asfdkoapvifmepcruinuiosnruoawesrxuesxs");
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("testing string '%-100.10s'\n", "asfdkoapvifmepcruinuiosnruoawesrxuesxs");
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("testing string '%-100.100s'\n", "asfdkoapvifmepcruinuiosnruoawesrxuesxs");
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("testing string '%100.s'\n", "asfdkoapvifmepcruinuiosnruoawesrxuesxs");
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("testing string '%-100s'\n", "asfdkoapvifmepcruinuiosnruoawesrxuesxs");
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("testing multiple strings '%%' '%s' '%-100.100s' '%10.5s' '%.10s'\n", "asfdkoapvifmepcruinuiosnruoawesrxuesxs", "ASDFGÖRESDVX", "sfja sdjasdcasd", "");
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("percentage string %s", "%");
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("usr:     f f f f:       >>>%s %s %s %s  string. gg!<<<\n", "this", "is", "a", "multi");
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("usr:     f f f f:       >>>%s%s%s%s  string. gg!<<<\n", "this", "is", "a", "multi");
	printf_ptr("ret is %d\n", ret);
}
