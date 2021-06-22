#include "../inc/core.h"
#include <assert.h>
#include <stdio.h>

typedef struct	s_test
{
	void		*raw;
	int			x;
	float		y;
	double		z;
}				t_test;

typedef union	s_un
{
	char		c;
	int			i;
	float		f;
}				t_un;

// Create and destroy an array

t_ssize		test_dealloc(void *data, t_size i)
{
	t_test	*ptr = data;
	free(ptr->raw);
	return(CR_CONTINUE);
}

t_ssize		test_print(void *data, t_size i)
{
	t_test	*ptr = data;
	printf("%p %d %f %lf\n", ptr->raw, ptr->x, ptr->y, ptr->z);
	return(CR_CONTINUE);
}

int			tests1()
{
	t_array	test;

	test = arr_new(1, sizeof(int));
	assert(test.raw.size == sizeof(int));
	assert(test.elem_size == sizeof(int));
	assert(test.len == 0);
	arr_free(&test);
	assert(arr_null(&test));
	return (1);
}

int			tests2()
{
	t_array	test;
	t_test *ptr;
	t_test *ptr2;
	t_test	struc;
	t_size	i;

	test = arr_new(1, sizeof(t_test));

	// Append 5 elements to the array.
	i= 0;
	while (i < 5)
	{
		struc = (t_test){malloc(1), 1, 1.5, 2.5};
		arr_add_last(&test, &struc);
		ptr = arr_get(&test, i);
		assert(mcmp(&struc, ptr, sizeof(t_test)) == 0);
		i++;
	}
	assert(test.len == 5);

	// Add 1 element to the middle of the array.
	struc = (t_test){malloc(1), 2, 3.5, 4.5};
	arr_add(&test, &struc, 3);
	ptr = arr_get(&test, 3);
	assert(mcmp(&struc, ptr, sizeof(t_test)) == 0);
	assert(test.len == 6);

	// Prepend one element to the array.
	struc = (t_test){malloc(1), 1, 0.5, 0.5};
	arr_add_first(&test, &struc);
	ptr = arr_get_first(&test);
	assert(mcmp(&struc, ptr, sizeof(t_test)) == 0);
	assert(test.len == 7);

	// Delete.
	free(ptr->raw);
	arr_del_first(&test);
	assert(test.len == 6);
	ptr = arr_get_first(&test);
	assert(mcmp(&struc, ptr, sizeof(t_test)) != 0);
	ptr2 = arr_get_last(&test);
	assert(ptr2->x == ptr->x);
	assert(ptr2->y == ptr->y);
	arr_iter(&test, test_dealloc);
	arr_free(&test);
	return (1);
}

t_ssize		print_data(void *data, t_size i)
{
	char	*ptr;

	ptr = data;
	printf("%c", *ptr);
	return (CR_CONTINUE);
}

int			tests3()
{
	t_array	test;
	t_array	comp;
	char	c = '6';
	int		pos;

	test = arr_new(1, sizeof(char));
	arr_put(&test, "0123456789", 10);
	arr_iter(&test, print_data);
	printf("\n");
	assert(mcmp((char *)test.raw.data, "0123456789", 10) == 0);
	arr_del(&test, arr_find(&test, &c));
	arr_iter(&test, print_data);
	printf("\n");
	assert(mcmp((char *)test.raw.data, "012345789", 9) == 0);

	comp = arr_new(1, sizeof(char));
	arr_put(&comp, "345", 3);
	pos = arr_search(&test, &comp);
	arr_del(&test, pos);
	arr_iter(&test, print_data);
	printf("\n");
	assert(mcmp((char *)test.raw.data, "01245789", 8) == 0);
	arr_take_last(&c, &test);
	arr_rotate(&test, 3);
	arr_iter(&test, print_data);
	printf("\n");
	assert(mcmp((char *)test.raw.data, "5780124", 7) == 0);
	arr_free(&test);
	arr_free(&comp);
	return (1);
}

int		main(void)
{
	tests1();
	tests2();
	tests3();
}

// printf("%p %d %f %lf\n", ptr2->raw, ptr2->x, ptr2->y, ptr2->z);
/*arr_iter(&test, test_print);*/
