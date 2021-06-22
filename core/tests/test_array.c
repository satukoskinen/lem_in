#include "../inc/core.h"

t_ssize	arr_assign(t_array *dst, void *data, t_size len)
{
	if (arr_null(dst) || dst->alloc_size > 0)
		return (CR_FAIL);
	dst->data = data;
	dst->reserv_size = len;
	dst->len = len;
	return (CR_SUCCESS);
}

t_ssize	print_char(void *data, t_size i)
{
	char	*ptr;

	ptr = data;
	printf("%c", *ptr);
	return (i);
}

int main(void)
{
	t_array	b;
	char	c;
	char	str[10] = "123456789";

	c = 'a';
	b = arr(sizeof(char));
	arr_assign(&b, str, 10);
	printf("\nlen: %zu alloc_size: %zu elem_size: %zu\n",
			b.len, b.alloc_size, b.elem_size);
	arr_del_last(&b);
	arr_del_last(&b);
	arr_add_last(&b, &c);
	arr_iter(&b, print_char);
	printf("\nlen: %zu alloc_size: %zu elem_size: %zu\n",
			b.len, b.alloc_size, b.elem_size);
	arr_free(&b);
}
