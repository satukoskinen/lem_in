#include "lem_in.h"

void	save_flow_path(t_parray *path, t_graph_node *src, t_graph_node *dst)
{
	t_graph_node	*node;
	t_graph_edge	*edge;
	size_t			i;
	int				add_every_other;

	node = src;
	parr_add_last(path, ((t_node_attr *)node->attr)->org);
	add_every_other = 1;
	while (strcmp(node->key, dst->key) != 0)
	{
		i = 0;
		while (i < node->in.len)
		{
			edge = parr_get(&node->in, i);
			if (((t_edge_attr *)edge->attr)->flow > 0)
				break ;
			i++;
		}
		if (add_every_other++ % 2 == 0)
		{
			if (parr_add_last(path, ((t_node_attr *)edge->u->attr)->org) != 1)
				lem_exit_error("ERROR");
		}
		node = edge->u;
	}
}

static void	insert_path_to_array(t_parray *paths, t_parray *path_to_add)
{
	size_t		i;
	t_parray	*path;

	i = 0;
	while (i < paths->len)
	{
		path = parr_get(paths, i);
		if (path->len > path_to_add->len)
			break ;
		i++;
	}
	if (parr_add(paths, path_to_add, i) != 1)
		lem_exit_error("ERROR");
}

static t_parray	*init_path_array(size_t	arr_size)
{
	t_parray	*array;

	array = (t_parray *)malloc(sizeof(t_parray));
	if (array == NULL)
		lem_exit_error("ERROR");
	*array = parr_new(arr_size);
	if (parr_null(array))
		lem_exit_error("ERROR");
	return (array);
}

t_parray	*lem_save_max_flow_paths(t_graph_node *s, t_graph_node *t,
	size_t max_flow)
{
	t_parray		*paths;
	t_parray		*path;
	size_t			i;
	t_graph_edge	*t_adj_edge;

	paths = init_path_array(max_flow);
	i = 0;
	while (i < t->in.len)
	{
		t_adj_edge = parr_get(&t->in, i);
		if (((t_edge_attr *)t_adj_edge->attr)->flow > 0)
		{
			path = init_path_array(2);
			parr_add_last(path, ((t_node_attr *)t->attr)->org);
			save_flow_path(path, t_adj_edge->u, s);
			insert_path_to_array(paths, path);
		}
		i++;
	}
	return (paths);
}
