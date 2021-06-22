#include "../inc/core.h"
#include <assert.h>

t_ssize	print_char(void *data, t_size i)
{
	char	*ptr;

	ptr = data;
	printf("%c", *ptr);
	return (i);
}

int	test_arr_add()
{
	t_array	arr;
	char	c;

	arr = arr(sizeof(char));
	c = 'A';
	arr_add(&arr, &c, 0);
	arr_add(&arr, &c, 0);
	arr_add(&arr, &c, 0);
	arr_add(&arr, &c, 0);
	char *tmp;

	tmp = malloc(1);
	arr_take(tmp, &arr, 0);
	arr_add(&arr, tmp, 0);
	free(tmp);
	arr_iter(&arr, print_char);
	arr_free(&arr);
	return (CR_SUCCESS);
}

int	main(void)
{
	test_arr_add();
}
