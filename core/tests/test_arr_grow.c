#include "../inc/core.h"












t_ssize	print_uint64(void *data, t_size i)
{
	t_uint64	*ptr;

	ptr = data;
	printf("%zu\n", *ptr);
	return (i);
}

void	test_arr_grow()
{
	t_array	test_1;
	t_uint64	x;
	test_1 = arr(1, sizeof(t_uint64));
	x = 0;
	t_size i = 0;
	while (i < 100)
	{
		arr_add_last(&test_1, &x);
		i++;
		x += 100;
	}
	arr_iter(&test_1, print_uint64);
}

int main(void)
{
	test_arr_grow();
}