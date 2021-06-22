#include "inc/core.h"
# include <string.h>
#include <time.h>
# include <unistd.h>

# define STRINGSIZE 1000

typedef t_raw	t_fstr;


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
}

int main(void)
{
	t_array	s1;
	t_array	s2;

	s1 = big_string();
	s2 = big_string();
	test_cstring_speed(s1, s2);
}