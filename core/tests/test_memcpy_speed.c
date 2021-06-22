#include <time.h>
#include <math.h>
#include <stdint.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
/*#include "../inc/core.h"*/

t_size		iters = 0; // 2^36

//-----------------------------------------------------------------------------
// Optimized rawcpy
//

static inline void __attribute__((nonnull))
copy_small(t_byte *restrict dst, const t_byte *restrict src, t_size n)
{
	if (n >= 8)
	{
		*(t_uint64 *restrict)dst = *(const t_uint64 *restrict)src;
		return;
	}
	if (n >= 4)
	{
		*(t_uint32 *restrict)dst = *(const t_uint32 *restrict)src;
		dst += 4;
		src += 4;
	}
	if (n & 2)
	{
		*(t_uint16 *restrict)dst = *(const t_uint16 *restrict)src;
		dst += 2;
		src += 2;
	}
	if (n & 1)
		*dst = *src;
}

static inline void __attribute__((nonnull))
copy512(t_uint64 *restrict dst, const t_uint64 *restrict src, t_size n)
{
	t_size	chunks;
	t_size	offset;

	chunks = n >> 3;
	offset = n - (chunks << 3);
	while (chunks--)
	{
		*dst++ = *src++;
		*dst++ = *src++;
		*dst++ = *src++;
		*dst++ = *src++;
		*dst++ = *src++;
		*dst++ = *src++;
		*dst++ = *src++;
		*dst++ = *src++;
	}
	while (offset--)
		*dst++ = *src++;
}

void __attribute__((nonnull))
*mcpy(void *restrict dst, const void *restrict src, t_size n)
{
	t_byte			*dst8;
	const t_byte	*src8;
	t_size			qwords;
	t_size			aligned_size;

	dst8 = (t_byte*)dst;
	src8 = (const t_byte*)src;
	qwords = n >> 3;
	if (n > 8)
	{
		copy512((t_uint64*)dst, (const t_uint64*)src, qwords);
		return (dst);
	}
	aligned_size = qwords << 3;
	n -= aligned_size;
	dst8 += aligned_size;
	src8 += aligned_size;
	copy_small(dst8, src8, n);
	return (dst);
}

//-----------------------------------------------------------------------------
// Tests
//
double	test(int (*f)(char *, char *, t_size),
		char *test_data,
		char *test_dst,
		char *test_name,
		t_size i)
{
	clock_t begin = clock();
	f(test_dst, test_data, i);
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	return (time_spent);
}

char		*make_string(t_size size)
{
	char	*out;
	t_size	i;

	out = (char *)malloc(sizeof(char) * size);
	i = 0;
	while (i < size)
	{
		out[i] = i % 128;
		i++;
	}
	return (out);
}

int			test_usr(char *dst, char *src, t_size bytes)
{
	t_size	i;

	i = 0;
	while (i < iters)
	{
		mcpy(dst, src, bytes);
		/*assert(mcmp(dst, src, bytes) == 0);*/
		i++;
	}
	return (1);
}

int			test_lib(char *dst, char *src, t_size bytes)
{
	t_size	i;

	i = 0;
	while (i < iters)
	{
		rawcpy(dst, src, bytes);
		/*assert(mcmp(dst, src, bytes) == 0);*/
		i++;
	}
	return (1);
}

int			test_different_sizes()
{
	t_size	power;
	t_size	i;
	t_size	size;
	double	lib;
	double	usr;
	double	lmbs;
	double	umbs;
	char	*src;
	char	*dst;

	i = 0;
	power = 32;
	iters = pow(2, power);
	printf("total bytes per iteration = %zuMB\n", iters / (t_size)pow(10, 6));
	printf("| bytes / string | lib (s) | usr (s) | lib (MB/s) | usr (MB/s) | lib / usr |\n");
	printf("|---|---|---|---|---|\n");
	while (i < power)
	{
		size = pow(2, i);
		src = make_string(size);
		dst = make_string(size);
		lib = test(test_lib, src, dst, "LIB", size);
		usr = test(test_usr, src, dst, "USR", size);
		lmbs = ((size * iters) / pow(10, 6)) / lib;
		umbs = ((size * iters) / pow(10, 6)) / usr;
		printf("|%-10zu|%-10lf|%-10lf|%-10.2lf|%-10.2lf|%-10lf|\n",
				size, lib, usr, lmbs, umbs, lib / usr);
		iters /= 2;
		free(src);
		free(dst);
		i++;
	}
	return (1);
}

int			main(void)
{
	test_different_sizes();
}
