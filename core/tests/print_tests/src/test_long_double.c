#include <stdio.h>
#include "core.h"

void	test_long_double(int use_ftprintf)
{
	int		ret;
	int		i;
	int		(*printf_ptr)(const char*, ...);

	long double	long_values[] = {
		3.14159265l, -958.125l, -14.2315l, -56.2012685l,
		1.0l, 0.1l, 0.01l, 0.001l,
		0.5l, 0.05l, 0.005l, 0.0005l,
		1.5l, 2.5l, 3.5l, 4.5l, 99.5l, 100.5l,
		-1.0l, -0.1l, -0.01l, -0.001l,
		-0.5l, -0.05l, -0.005l, -0.0005l,
		-1.5l, -2.5l, -3.5l, -4.5l, -99.5l, -100.5l,
		0.0l, -0.0l,
		0.87650894255l,
		0.125l,
		0.15l, 0.25l, 0.35l, 0.45l,
		0.55l, 0.65l, 0.75l, 0.85l,
		0.95l, 0.1245l, 0.1255l, 0.1265l,
		-0.15l, -0.25l, -0.35l, -0.45l,
		-0.55l, -0.65l, -0.75l, -0.85l,
		-0.95l, -0.1245l, -0.1255l, -0.1265l,
		454423.343242374412345l,
		13.99999l,
		1.1l,
		2.5l,
		3.0/256l,
		36028797018963968.2433l,
		-9007199254740992.0l,
		18014398509481984.0l,
		18014398509481985.0l,
		18014398509481986.0l,
		36028797018963968.2433l,
		-1.0/0.0l, 1.0/0.0l, 0.0/0.0l, -0.0/0.0l
	};

	if (use_ftprintf)
		printf_ptr = print;
	else
		printf_ptr = printf;

	printf_ptr("---------------------------\n");
	printf_ptr("Basic tests for long double %%Lf %%LF\n");
	printf_ptr("---------------------------\n");

	i = 0;
	while (i < 50)
	{
		ret = printf_ptr("%%Lf '%Lf'\n", long_values[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("%%.Lf '%.Lf' %%.0Lf '%.0Lf' %%.1Lf '%.1Lf' %%.10Lf '%.10Lf' %%.15Lf '%.15Lf'\n", long_values[i], long_values[i], long_values[i], long_values[i], long_values[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("%%10.Lf '%10.Lf' %%10.0Lf '%10.0Lf' %%10.1Lf '%10.1Lf' %%10.10Lf '%10.10Lf' %%10.15Lf '%10.15Lf'\n", long_values[i], long_values[i], long_values[i], long_values[i], long_values[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("%%.2Lf '%.2Lf' %%.3Lf '%.3Lf' %%.4Lf '%.4Lf' %%.5Lf '%.5Lf' %%.6Lf '%.6Lf'\n", long_values[i], long_values[i], long_values[i], long_values[i], long_values[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("%%#Lf '%#Lf'\n", long_values[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("%%#.Lf '%#.Lf' %%#.0Lf '%#.0Lf' %%#.1Lf '%#.1Lf' %%#.10Lf '%#.10Lf' %%#.15Lf '%#.15Lf'\n", long_values[i], long_values[i], long_values[i], long_values[i], long_values[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("%%0Lf '%0Lf' %%#0Lf '%#0Lf' %%0#.1Lf '%0#.1Lf' %%0 Lf '%0 Lf' %%+0Lf '%#+0Lf'\n", long_values[i], long_values[i], long_values[i], long_values[i], long_values[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("%%010Lf '%010Lf' %%#010Lf '%#010Lf' %%0#10.1Lf '%0#10.1Lf' %%0 10Lf '%0 10Lf' %%+010Lf '%#+010Lf'\n", long_values[i], long_values[i], long_values[i], long_values[i], long_values[i]);
		printf_ptr("ret is %d\n", ret);

		ret = printf_ptr("%%+Lf '%+Lf' %%#+0Lf '%#+0Lf' %%+ 1Lf '%+ 1Lf' %%#+.Lf '%#+.Lf' %%0.10Lf '%0.10Lf'\n", long_values[i], long_values[i], long_values[i], long_values[i], long_values[i]);
		printf_ptr("ret is %d\n", ret);

		printf_ptr("\n\n\n\n\n\n\n\n");

		i++;
	}
}