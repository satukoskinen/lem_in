#include "lem_in.h"

void	save_flow_path(t_parray *path, t_graph_node *src, t_graph_node *dst)
{
	t_graph_node	*node;
	t_graph_edge	*edge;
	size_t			i;
	int				add_every_other;

	node = src;
	parr_add_last(path, ((t_node_attr *)node->attr)->org);
	add_every_other = 0;
	while (node->id != dst->id)
	{
		i = 0;
		while (i < node->in.len)
		{
			edge = arr_get(&node->in, i);
			if (((t_edge_attr *)edge->attr)->flow > 0)
			{
				add_every_other++;
				if (add_every_other % 2 == 0)
					parr_add_last(path, ((t_node_attr *)edge->src->attr)->org);
				node = edge->src;
				break ;
			}
			i++;
		}
	}
}

static ssize_t	insert_path_to_array(t_array *paths, t_parray *path_to_add)
{
	size_t		i;
	t_parray	*path;

	i = 0;
	while (i < paths->len)
	{
		path = arr_get(paths, i);
		if (path->len > path_to_add->len)
			return (arr_add(paths, path_to_add, i));
		i++;
	}
	return (arr_add_last(paths, path_to_add));
}

t_array	save_max_flow_paths(t_graph_node *s, t_graph_node *t, size_t max_flow)
{
	t_array			paths;
	t_parray		path;
	size_t			i;
	t_graph_edge	*sink_edge;

	paths = arr_new(max_flow, sizeof(t_parray));
	if (paths.data == NULL)
		return (CR_ARR_NULL);
	i = 0;
	while (i < t->in.len)
	{
		sink_edge = arr_get(&t->in, i);
		if (((t_edge_attr *)sink_edge->attr)->flow > 0)
		{
			path = parr_new(sizeof(t_graph_node *));
			parr_add_last(&path, ((t_node_attr *)t->attr)->org);
			save_flow_path(&path, sink_edge->src, s);
			insert_path_to_array(&paths, &path);
		}
		i++;
	}
	return (paths);
}

