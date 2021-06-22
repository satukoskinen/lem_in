#include <stdio.h>
#include "core.h"

void	test_pointer(void)
{
	int	ret;
	int	test_value;
	int	*test_pointer;
	int (*printf_ptr)(const char*, ...);

	test_value = 42;
	test_pointer = &test_value;

	printf_ptr = print;

	ret = printf_ptr("testing test_pointer %%p '%p'\n", test_pointer);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("testing &test_value %%p '%p'\n", &test_value);
	printf_ptr("ret is %d\n", ret);
	
	ret = printf_ptr("testing test_pointer %%p '%20p'\n", test_pointer);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("testing test_pointer %%p '%200p'\n", test_pointer);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("testing test_pointer %%p '%-20p'\n", test_pointer);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("testing test_pointer %%p '%5p'\n", test_pointer);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("testing test_pointer %%p '%p'\n", NULL);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("testing test_pointer %%p '%-20p'\n", NULL);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("testing test_pointer %%p '%5p'\n", NULL);
	printf_ptr("ret is %d\n", ret);

	printf_ptr = printf;

	ret = printf_ptr("testing test_pointer %%p '%p'\n", test_pointer);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("testing &test_value %%p '%p'\n", &test_value);
	printf_ptr("ret is %d\n", ret);
	
	ret = printf_ptr("testing test_pointer %%p '%20p'\n", test_pointer);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("testing test_pointer %%p '%200p'\n", test_pointer);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("testing test_pointer %%p '%-20p'\n", test_pointer);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("testing test_pointer %%p '%5p'\n", test_pointer);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("testing test_pointer %%p '%p'\n", NULL);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("testing test_pointer %%p '%-20p'\n", NULL);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("testing test_pointer %%p '%5p'\n", NULL);
	printf_ptr("ret is %d\n", ret);
}