#include "../lem_in.h"











t_graph_edge	*graph_find_edge(t_graph *g,
				const char *src_key,
				const char *dst_key)
{
	t_graph_node	*node;
	t_graph_edge	*out;
	size_t			i;

	node = graph_find_node(g, src_key);
	i = 0;
	while (i < node->out.len)
	{
		out = arr_get(&node->out, i);
		if (s_cmp(out->dst->key, dst_key) == 0)
			return (out);
		i++;
	}
	return (NULL);
}

ssize_t	add_edges(t_graph *src, t_graph *new)
{
	size_t			i;
	size_t			j;
	t_edge_attr		*edge_attr;
	t_edge_attr		*rev_edge_attr;
	char			*in_key;
	char			*out_key;
	t_graph_node	*in;
	t_graph_node	*out;
	t_graph_node	*node;
	t_graph_edge	*edge;

	i = 0;
    while (i < src->data.capacity)
	{
        if (!map_null_node(&src->data.node[i]))
		{
			node = (t_graph_node *)src->data.node[i].data;
			j = 0;
			while (j < node->in.len)
			{
				edge = arr_get(&node->in, j);
				in_key = s_new(s_len(
						edge->src->key) + 3);
				sprintf(in_key, "%s_in",
						edge->src->key);
				out_key = s_new(s_len(
						edge->dst->key) + 4);
				sprintf(out_key, "%s_out",
						edge->dst->key);
				in = graph_find_node(new, in_key);
				out = graph_find_node(new, out_key);
				edge_attr = init_edge_attr(1);
				graph_add_edge(new, out->key, in->key, edge_attr);
				rev_edge_attr = init_edge_attr(0);
				graph_add_edge(new, in->key, out->key, rev_edge_attr);
				edge_attr->reverse_edge = graph_find_edge(new, in->key, out->key);
				rev_edge_attr->reverse_edge = graph_find_edge(new, out->key, in->key);
				j++;
			}
		}
		i++;
	}
	return (1);
}

static t_node_attr	*init_split_node_attr(const char *name, char *suffix, t_graph_node *org)
{
	t_node_attr	*node_attr;

	node_attr = (t_node_attr *)malloc(sizeof(t_node_attr));
	if (node_attr == NULL)
		return (NULL);
	node_attr->name = s_join(name, suffix);
	if (node_attr->name == NULL)
	{
		free(node_attr);
		return (NULL);
	}
	node_attr->org = org;
	node_attr->coordinates.x = 0;
	node_attr->coordinates.y = 0;
	return (node_attr);
}

ssize_t	add_nodes(t_graph *src, t_graph *new)
{
	size_t	i;
	t_node_attr	*in_node_attr;
	t_node_attr	*out_node_attr;
	t_edge_attr	*edge_attr;
	t_edge_attr	*rev_edge_attr;

    i = 0;
    while (i < src->data.capacity)
    {
        if (!map_null_node(&src->data.node[i]))
		{
			in_node_attr = init_split_node_attr(src->data.node[i].key, "_in", src->data.node[i].data);
			out_node_attr = init_split_node_attr(src->data.node[i].key, "_out", src->data.node[i].data);
			graph_add_node(new, in_node_attr->name, in_node_attr);
			graph_add_node(new, out_node_attr->name, out_node_attr);
			edge_attr = init_edge_attr(1);
			graph_add_edge(new, in_node_attr->name, out_node_attr->name, edge_attr);
			rev_edge_attr = init_edge_attr(0);
			graph_add_edge(new, out_node_attr->name, in_node_attr->name, rev_edge_attr);
			edge_attr->reverse_edge = graph_find_edge(new, out_node_attr->name, in_node_attr->name);
			rev_edge_attr->reverse_edge = graph_find_edge(new, in_node_attr->name, out_node_attr->name);
		}
        i++;
    }
	return (1);
}

t_graph	copy_vertex_disjoint(t_graph *src)
{
	t_graph	new;

	new = graph_new(NULL);
	add_nodes(src, &new);
	add_edges(src, &new);
	return (new);
}
