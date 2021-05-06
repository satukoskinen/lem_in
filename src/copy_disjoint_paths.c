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

t_graph	copy_vertex_disjoint(t_graph *src)
{
	t_graph	new;
	t_node_attr	in_attr;
	t_node_attr	out_attr;
	t_edge_attr	e_attr;
	t_edge_attr	rev_e_attr;
	char	*in_key;
	char	*out_key;
	t_graph_node	*in;
	t_graph_node	*out;
    size_t  i;

	new = graph_new(NULL);
    i = 0;
    while (i < src->data.capacity)
    {
        if (!map_null_node(&src->data.node[i]))
		{
			in_attr.name = s_new(s_len(
						src->data.node[i].key) + 1);
			sprintf(in_attr.name, "%si",
						src->data.node[i].key);
			in_attr.org = src->data.node[i].data;
			out_attr.name = s_new(s_len(
						src->data.node[i].key) + 1);
			sprintf(out_attr.name, "%so",
						src->data.node[i].key);
			out_attr.org = src->data.node[i].data;
			graph_add_node(&new, in_attr.name, &in_attr);
			graph_add_node(&new, out_attr.name, &out_attr);
		}
        i++;
    }
    while (i < src->data.capacity)
	{
        if (!map_null_node(&src->data.node[i]))
		{
			in_key = s_new(s_len(
						src->data.node[i].key) + 1);
			sprintf(in_key, "%si",
						src->data.node[i].key);
			out_key = s_new(s_len(
						src->data.node[i].key) + 1);
			sprintf(out_key, "%so",
						src->data.node[i].key);
			in = graph_find_node(&new, in_key);
			out = graph_find_node(&new, out_key);
			e_attr.flow = 0;
			e_attr.capacity = 1;
			e_attr.reverse_edge = (t_graph_edge *)malloc(sizeof(t_graph_edge));
			e_attr.reverse_edge->src = in;
			e_attr.reverse_edge->dst = out;
			rev_e_attr.flow = 0;
			rev_e_attr.capacity = 0;
			rev_e_attr.reverse_edge->src = in;
			rev_e_attr.reverse_edge->dst = out;
			e_attr.reverse_edge-> = 0;
			graph_add_edge(&new, in_key, out_key, );
		}
		i++;
	}
}
