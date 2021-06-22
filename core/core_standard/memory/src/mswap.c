#include "../../../inc/core.h"

static inline void	mswap512(t_uint64 *a, t_uint64 *b)
{
	mswap64(&a[0], &b[0]);
	mswap64(&a[1], &b[1]);
	mswap64(&a[2], &b[2]);
	mswap64(&a[3], &b[3]);
	mswap64(&a[4], &b[4]);
	mswap64(&a[5], &b[5]);
	mswap64(&a[6], &b[6]);
	mswap64(&a[7], &b[7]);
}

static inline void	swap_small(t_byte *a, t_byte *b, t_size n)
{
	if (n >= 8)
	{
		mswap64((t_uint64 *)a, (t_uint64 *)b);
		return ;
	}
	if (n >= 4)
	{
		mswap32((t_uint32 *)a, (t_uint32 *)b);
		a += 4;
		b += 4;
	}
	if (n & 2)
	{
		mswap16((t_uint16 *)a, (t_uint16 *)b);
		a += 2;
		b += 2;
	}
	if (n & 1)
		mswap8((t_uint8 *)a, (t_uint8 *)b);
}

static inline void	swap_big(t_uint64 *a, t_uint64 *b, t_size n)
{
	t_size	chunks;
	t_size	offset;

	chunks = n >> 3;
	offset = n - (chunks << 3);
	while (chunks--)
	{
		mswap512(a, b);
		a += 8;
		b += 8;
	}
	while (offset--)
	{
		mswap64(a, b);
		a += 1;
		b += 1;
	}
}

void	mswap(void *a, void *b, t_size n)
{
	t_byte	*raw_a;
	t_byte	*raw_b;
	t_size	qwords;
	t_size	aligned_size;

	raw_a = a;
	raw_b = b;
	if (raw_a == raw_b)
		return ;
	qwords = n >> 3;
	aligned_size = qwords << 3;
	if (n >= 8)
		swap_big((t_uint64 *)a, (t_uint64 *)b, qwords);
	aligned_size = qwords << 3;
	n -= aligned_size;
	raw_a += aligned_size;
	raw_b += aligned_size;
	swap_small(raw_a, raw_b, n);
}
