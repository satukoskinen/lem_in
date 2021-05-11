/******************************************************************************
 *
 * \authors Satu Koskinen, Julius Koskela
 *
 * \brief Create a vertex disjoint transformation of a graph.
 *
 * \param src Source graph.
 *
 * \return A new transformed graph.
 *
 *****************************************************************************/

#include "../lem_in.h"

/******************************************************************************
 *
 *****************************************************************************/

static ssize_t	add_edges(
	t_graph *new,
	const char *src_key,
	const char *dst_key)
{
	t_edge_attr		*edge_attr;
	t_edge_attr		*rev_edge_attr;
	t_graph_node	*src;
	t_graph_node	*dst;

	src = graph_find_node(new, src_key);
	dst = graph_find_node(new, dst_key);
	edge_attr = lem_init_edge_attr(1);
	rev_edge_attr = lem_init_edge_attr(0);
	graph_add_edge(new, src->key, dst->key, edge_attr);
	graph_add_edge(new, dst->key, src->key, rev_edge_attr);
	edge_attr->reverse_edge = graph_find_edge(new, dst->key, src->key);
	rev_edge_attr->reverse_edge = graph_find_edge(new, src->key, dst->key);
	return (1);
}

/******************************************************************************
 *
 *****************************************************************************/

static char	*split_edge(void *parse_dst, void *data, const char *key)
{
	t_graph_node	*node;
	t_graph_edge	*edge;
	size_t			i;
	char			*src_key;
	char			*dst_key;

	node = data;
	i = 0;
	while (i < node->in.len)
	{
		edge = arr_get(&node->in, i);
		src_key = s_join(edge->src->key, "_out");
		dst_key = s_join(edge->dst->key, "_in");
		add_edges((t_graph *)parse_dst, src_key, dst_key);
		free(src_key);
		free(dst_key);
		i++;
	}
	return ((char *)key);
}

/******************************************************************************
 *
 *****************************************************************************/

static char	*split_node(void *parse_dst, void *data, const char *key)
{
	t_graph			*graph;
	t_graph_node	*node;
	t_node_attr		*in_node_attr;
	t_node_attr		*out_node_attr;
	char			*new_key;

	graph = parse_dst;
	node = data;
	new_key = s_join(key, "_in");
	in_node_attr = lem_init_node_attr(new_key, (t_coordinates){0, 0}, node);
	new_key = s_join(key, "_out");
	out_node_attr = lem_init_node_attr(new_key, (t_coordinates){0, 0}, node);
	graph_add_node(graph, in_node_attr->name, in_node_attr);
	graph_add_node(graph, out_node_attr->name, out_node_attr);
	add_edges(graph, in_node_attr->name, out_node_attr->name);
	return ((char *)key);
}

/******************************************************************************
 *
 *****************************************************************************/

t_graph	lem_transform_vertex_disjoint(t_graph *src)
{
	t_graph	new;
	char	*source_key;
	char	*sink_key;

	new = lem_init_graph();
	map_parse(&src->data, &new, split_node);
	map_parse(&src->data, &new, split_edge);
	source_key = s_join(((t_graph_attr *)src->attr)->source->key, "_out");
	sink_key = s_join(((t_graph_attr *)src->attr)->sink->key, "_in");
	((t_graph_attr *)new.attr)->source = graph_find_node(&new, source_key);
	((t_graph_attr *)new.attr)->sink = graph_find_node(&new, sink_key);
	free(source_key);
	free(sink_key);
	return (new);
}
