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

void	print_paths(t_array *paths)
{
	t_array		*path;
	t_vertex	*vertex;
	size_t		i;
	size_t		j;

	ft_printf("number of paths: %d\n", array_size(paths));
	i = 0;
	while (i < array_size(paths))
	{
		path = *(t_array **)array_get(paths, i);
		ft_printf("path %d: size %d\n", i, array_size(path));
		j = 0;
		while (j < array_size(path))
		{
			vertex = *(t_vertex **)array_get(path, j);
			ft_printf("vertex %d: id %s\n", j, vertex->id);
			j++;
		}
		i++;
	}
}
