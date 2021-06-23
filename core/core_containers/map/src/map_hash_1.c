/******************************************************************************
 * \authors
 * \brief
 * \param
 * \return
 *****************************************************************************/

#include "../../../inc/core.h"

static inline t_uint64	shift(t_uint64 x, t_uint64 n)
{
	return ((x << n) >> n);
}

t_uint64	map_hash_1(const char *str)
{
	t_size		wrdlen;
	t_uint32	prime;
	t_uint64	hash64;
	t_size		cycles;
	t_size		ndhead;

	ndhead = 0;
	prime = 591798841;
	hash64 = 14695981039346656037LLU;
	wrdlen = s_len(str);
	if (wrdlen > 8)
	{
		cycles = ((wrdlen - 1) >> 4) + 1;
		ndhead = wrdlen - (cycles << 3);
		while (cycles--)
		{
			hash64 = (hash64 ^ (*(t_uint64 *)(str))) * prime;
			hash64 = (hash64 ^ (*(t_uint64 *)(str + ndhead))) * prime;
			str += 8;
		}
		return (hash64 ^ (hash64 >> 32));
	}
	mcpy(&ndhead, str, wrdlen);
	hash64 = (hash64 ^ shift(ndhead, (8 - wrdlen) << 3)) * prime;
	return (hash64 ^ (hash64 >> 32));
}
