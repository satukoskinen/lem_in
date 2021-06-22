
#include "../inc/core.h"
#include "assert.h"

t_size	iters = 100000;

void rand_str(char *dest, t_size length)
{
    char charset[] = "0123456789"
                     "abcdefghijklmnopqrstuvwxyz"
                     "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    while (length-- > 0)
	{
        t_size index = (double) rand() / RAND_MAX * (sizeof charset - 1);
        *dest++ = charset[index];
    }
    *dest = '\0';
}


t_ssize	test_map_insert_speed(t_map *testmap)
{
	char	key[7];
	t_size	val = 666;
	t_size	i;

	i = 0;
	while (i < iters)
	{
    	rand_str(key, sizeof key - 1);
		map_add(testmap, &val, key);
		i++;
	}
	return (1);
}

int main(void)
{
	t_map	testmap;

	testmap = map();
	test_map_insert_speed(&testmap);
}

