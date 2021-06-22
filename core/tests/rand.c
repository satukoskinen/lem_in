#include "inc/core.h"
#include "inc/types.h"
#include <time.h>

static t_ssize	print_int64(void *data, t_size i)
{
	int	*ptr;

	ptr = data;
	printf("%d ", *ptr);
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

int	main(int argc, char **argv)
{
	t_array	out;
	t_size	size;
	t_size	i;

	size = atoi(argv[1]);
	out = arr_new(size, sizeof(t_int64));
	i = 0;
	while (i < size)
	{
		arr_add_last(&out, &i);
		i++;
	}
	shuffle(&out, size);
	arr_iter(&out, print_int64);
	arr_free(&out);
}
