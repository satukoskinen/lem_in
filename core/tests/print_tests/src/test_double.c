#include <stdio.h>
#include "core.h"

void	test_double(int use_ftprintf)
{
	int		ret;
	int		i;
	int		(*printf_ptr)(const char*, ...);

	double	values[] = {
		3.14159265, -958.125, -14.2315, -56.2012685,
		1.0, 0.1, 0.01, 0.001,
		1.5, 2.5, 3.5, 4.5, 99.5, 100.5,
		0.5, 0.05, 0.005, 0.0005,
		-1.0, -0.1, -0.01, -0.001,
		-1.5, -2.5, -3.5, -4.5, -99.5, -100.5,
		-0.5, -0.05, -0.005, -0.0005,
		0.0, -0.0,
		0.87650894255,
		0.125,
		0.15, 0.25, 0.35, 0.45,
		0.55, 0.65, 0.75, 0.85,
		0.95, 0.1245, 0.1255, 0.1265,
		-0.15, -0.25, -0.35, -0.45,
		-0.55, -0.65, -0.75, -0.85,
		-0.95, -0.1245, -0.1255, -0.1265,
		454423.343242374412345,
		13.99999,
		0.87650894255,
		1.1,
		2.5,
		3.0/256,
		36028797018963968.2433,
		-9007199254740992.0,
		18014398509481984.0,
		18014398509481985.0,
		18014398509481986.0,
		36028797018963968.2433,
		-1.0/0.0, 1.0/0.0, 0.0/0.0, -0.0/0.0,
		};

	if (use_ftprintf)
		printf_ptr = print;
	else
		printf_ptr = printf;

	printf_ptr("---------------------------\n");
	printf_ptr("Basic tests for double %%f %%F\n");
	printf_ptr("---------------------------\n");

	i = 0;
	while (i < 76)
	{
		ret = printf_ptr("%%f '%f' %%lf '%lf'\n", values[i], values[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("%%.f '%.f' %%.0f '%.0f' %%.1f '%.1f' %%.10f '%.10f' %%.15f '%.15f'\n", values[i], values[i], values[i], values[i], values[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("%%10.f '%10.f' %%10.0f '%10.0f' %%10.1f '%10.1f' %%10.10f '%10.10f' %%10.15f '%10.15f'\n", values[i], values[i], values[i], values[i], values[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("%%.2f '%.2f' %%.3f '%.3f' %%.4f '%.4f' %%.5f '%.5f' %%.6f '%.6f'\n", values[i], values[i], values[i], values[i], values[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("%%#f '%#f'\n", values[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("%%#.f '%#.f' %%#.0f '%#.0f' %%#.1f '%#.1f' %%#.10f '%#.10f' %%#.15f '%#.15f'\n", values[i], values[i], values[i], values[i], values[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("%%0f '%0f' %%#0f '%#0f' %%0#.1f '%0#.1f' %%0 f '%0 f' %%+0f '%#+0f'\n", values[i], values[i], values[i], values[i], values[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("%%010f '%010f' %%#010f '%#010f' %%0#10.1f '%0#10.1f' %%0 10f '%0 10f' %%+010f '%#+010f'\n", values[i], values[i], values[i], values[i], values[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("%%+f '%+f' %%#+0f '%#+0f' %%+ 1f '%+ 1f' %%#+.f '%#+.f' %%0.10f '%0.10f'\n", values[i], values[i], values[i], values[i], values[i]);
		printf_ptr("ret is %d\n", ret);

		printf_ptr("\n\n\n\n\n\n\n\n");

		i++;
	}
}
