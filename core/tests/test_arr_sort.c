#include "inc/core.h"
#include <time.h>

t_ssize	CMP(void *a, void *b)
{
	int	*ai;
	int	*bi;

	ai = a;
	bi = b;
	if (*ai <= *bi)
		return (0);
	return (1);
}

t_ssize	PRINT(void *data, t_size i)
{
	int	*ptr = data;
	print("%d ", *ptr);
	return (i);
}

static void	shuffle(t_array *arr, int n)
{
	t_int64	i;
	t_int64	j;
	t_int64	*s;
	t_int64	*t;

	if (n < 1)
		return ;
	srand(time(NULL));
	i = 0;
	while (i < n - 1)
	{
		j = i + rand() / (RAND_MAX / (n - i) + 1);
		s = arr_get(arr, i);
		t = arr_get(arr, j);
		mswap(s, t, sizeof(t_int64));
		i++;
	}
}

t_array	generate(int size)
{
	t_array	out;
	t_size	i;

	out = arr_new(size, sizeof(t_int64));
	i = 0;
	while (i < size)
	{
		arr_add_last(&out, &i);
		i++;
	}
	shuffle(&out, size);
	return (out);
}

int	main(int argc, char **argv)
{
	t_array	a1;
	
	a1 = generate(s_toi(argv[1]));
	arr_iter(&a1, PRINT);
	print("\nlist size = %d\n", a1.len);
	arr_sort(&a1, CMP);
	arr_iter(&a1, PRINT);
}
