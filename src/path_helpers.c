#include "lem_in.h"
#include "libft.h"

t_array	*insert_path_to_array(t_array **paths, t_array **path)
{
	size_t	i;
	t_array	*path_i;

	i = 0;
	while (i < array_size(*paths))
	{
		path_i = *(t_array **)array_get(*paths, i);
		if (array_size(*path) < array_size(path_i))
			return (array_insert(paths, path, i));
		i++;
	}
	return (array_add(paths, path));
}
