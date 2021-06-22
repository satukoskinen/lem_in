#include "../inc/core.h"

t_ssize	print_char(void *data, t_size i)
{
	char	*ptr;

	ptr = data;
	printf("%c", *ptr);
	return (i);
}

int	main(void)
{
	t_array	a;
	char	c;

	c = 'A';
	a = arr(1, sizeof(char));
	arr_put(&a, "abcdefg", 3);
	arr_add_last(&a, &c);
	arr_iter(&a, print_char);
	printf("\n");
	arr_rotate(&a, 1);
	arr_iter(&a, print_char);
	printf("\n");
	arr_rotate(&a, 1);
	arr_iter(&a, print_char);
	printf("\n");
	arr_rotate(&a, 1);
	arr_iter(&a, print_char);
	printf("\n");
	arr_free(&a);
}

