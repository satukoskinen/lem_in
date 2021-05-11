#include "lem_in.h"

ssize_t	lem_print_node(void *data, size_t i)
{
	t_graph_node	*tmp;
	t_node_attr		*attr;

	tmp = data;
	attr = tmp->attr;
	print("key [%s] value [%d]\n",
		tmp->key, attr->value);
	arr_iter(&tmp->in, lem_print_edge);
	arr_iter(&tmp->out, lem_print_edge);
	return ((ssize_t)i);
}
