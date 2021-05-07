#include "lem_in.h"
#include "libft.h"

ssize_t	print_string(void *data, size_t i)
{
	ft_printf("%s\n", (char *)data);
	return ((ssize_t)i);
}

ssize_t	print_edge(void *data, size_t i)
{
	t_graph_edge	*tmp;
	t_edge_attr		*attr;

	tmp = data;
	attr = tmp->attr;
	ft_printf("src %-5s -> dst %-5s flow %d capacity %d\n",
		tmp->src->key, tmp->dst->key, attr->flow, attr->capacity);
	return ((ssize_t)i);
}

ssize_t	print_node(void *data, size_t i)
{
	t_graph_node	*tmp;
	t_node_attr		*attr;

	tmp = data;
	attr = tmp->attr;
	ft_printf("key [%s] value [%d]\n",
		tmp->key, attr->value);
	arr_iter(&tmp->in, print_edge);
	arr_iter(&tmp->out, print_edge);
	return ((ssize_t)i);
}

ssize_t	print_path(void *data, size_t i)
{
	ft_printf("Path %d:\n", (int)i);
	parr_iter((t_parray *)data, print_node);
	return ((ssize_t)i);
}

ssize_t	print_path_combinations(void *data, size_t i)
{
	t_array	*path;

	path = data;
	ft_printf("Iteration %d: %d paths found\n", (int)i, path->len);
	arr_iter(path, print_path);
	return ((ssize_t)i);
}
