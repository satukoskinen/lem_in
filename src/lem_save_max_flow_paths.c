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
	while (strcmp(node->key, dst->key) != 0)
	{
		i = 0;
		while (i < node->in.len)
		{
			edge = parr_get(&node->in, i);
			if (((t_edge_attr *)edge->attr)->flow > 0)
			{
				add_every_other++;
				if (add_every_other % 2 == 0)
					parr_add_last(path, ((t_node_attr *)edge->u->attr)->org);
				node = edge->u;
				break ;
			}
			i++;
		}
	}
}

static ssize_t	insert_path_to_array(t_parray *paths, t_parray *path_to_add)
{
	size_t		i;
	t_parray	*path;

	i = 0;
	while (i < paths->len)
	{
		path = parr_get(paths, i);
		if (path->len > path_to_add->len)
			return (parr_add(paths, path_to_add, i));
		i++;
	}
	return (parr_add_last(paths, path_to_add));
}

t_parray	*lem_save_max_flow_paths(t_graph_node *s, t_graph_node *t,
	size_t max_flow)
{
	t_parray		*paths;
	t_parray		*path;
	size_t			i;
	t_graph_edge	*sink_edge;

	paths = malloc(sizeof(t_parray));
	*paths = parr_new(max_flow);
	if (parr_null(paths))
		return (&CR_PARR_NULL);
	i = 0;
	while (i < t->in.len)
	{
		sink_edge = parr_get(&t->in, i);
		if (((t_edge_attr *)sink_edge->attr)->flow > 0)
		{
			path = malloc(sizeof(t_parray));
			*path = parr_new(sizeof(t_graph_node *));
			parr_add_last(path, ((t_node_attr *)t->attr)->org);
			save_flow_path(path, sink_edge->u, s);
			insert_path_to_array(paths, path);
		}
		i++;
	}
	return (paths);
}
