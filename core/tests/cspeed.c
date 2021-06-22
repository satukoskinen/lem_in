#include "inc/core.h"
# include <string.h>
#include <time.h>
# include <unistd.h>

# define STRINGSIZE 100000

typedef t_raw	t_fstr;

t_fstr	fstr_new(t_size len)
{
	t_fstr	new;

	new = raw(len);
	return (new);
}

t_fstr	fstr(char *str)
{
	t_fstr	new;
	t_size	len;

	len = s_len(str);
	new = fstr_new(len);
	new.data = mcpy(new.data, str, len);
	return (new);
}

void	fstr_write(t_fstr str)
{
	if (!(write(1, str.data, str.size)))
		return ;
}

t_fstr	fstr_join(t_fstr dst, t_fstr src)
{
	t_fstr	new;
	t_byte	*raw_ptr;

	new = fstr_new(dst.size + src.size);
	raw_ptr = new.data;
	raw_ptr = mcpy(raw_ptr, dst.data, dst.size);
	raw_ptr += dst.size;
	raw_ptr = mcpy(raw_ptr, src.data, src.size);
	raw_free(&dst);
	return (new);
}

t_size	iters = 5000;

t_fstr	big_string()
{
	t_fstr	str;
	t_size	i;
	str = raw(sizeof(char) * STRINGSIZE);
	i = 0;
	while (i < STRINGSIZE)
	{
		str.data[i] = 'a';
		i++;
	}
	return (str);
}

double	test_cstring_speed(t_fstr s1, t_fstr s2)
{
	double	time;
	t_size	i;
	clock_t begin = clock();

	i = 0;
	while (i < iters)
	{
		s1 = fstr_join(s1, s2);
		i++;
	}
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("TEST CSTRING\n%f\n", time_spent);
	printf("SIZE\n%llu\n", s1.size);
}

int main(void)
{
	t_fstr	s1;
	t_fstr	s2;

	s1 = big_string();
	s2 = big_string();
	test_cstring_speed(s1, s2);
}