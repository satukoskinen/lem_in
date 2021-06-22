#include "inc/core.h"
# include <string.h>
#include <time.h>

# define STRINGSIZE 100000

t_size	iters = 500;

char	*big_string()
{
	char	*str;
	t_size	i;
	str = malloc(sizeof(char) * STRINGSIZE + 1);
	i = 0;
	while (i < STRINGSIZE)
	{
		str[i] = 'a';
		i++;
	}
	str[i] = '\0';
	return (str);
}

double	test_cstring_speed(char *s1, char *s2)
{
	char	*tmp;
	double	time;
	t_size	i;
	clock_t begin = clock();

	i = 0;
	while (i < iters)
	{
		tmp = s_join(s1, s2);
		free(s1);
		s1 = tmp;
		i++;
	}
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("TEST STRING\n%f\n", time_spent);
}

int main(void)
{
	char	*s1;
	char	*s2;

	s1 = big_string();
	s2 = big_string();
	test_cstring_speed(s1, s2);
}