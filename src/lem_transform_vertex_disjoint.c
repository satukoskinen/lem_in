#include "lem_in.h"

/*
 * Add edges and reverse edges to the graph.
 */

static void	add_edges(
	t_graph *graph,
	const char *src_key,
	const char *dst_key)
{
	t_edge_attr		*edge_attr;
	t_edge_attr		*rev_edge_attr;
	t_graph_node	*src;
	t_graph_node	*dst;
	t_graph_edge	*rev_edge;

	src = graph_find_node(graph, src_key);
	dst = graph_find_node(graph, dst_key);
	edge_attr = lem_init_edge_attr(1);
	rev_edge_attr = lem_init_edge_attr(0);
	if (!edge_attr || !rev_edge_attr)
		lem_exit_error("edge attr");
	if (!graph_add_edge(graph, src->key, dst->key, edge_attr)
		|| !graph_add_edge(graph, dst->key, src->key, rev_edge_attr))
		lem_exit_error("add edge");
	rev_edge = graph_find_edge(graph, dst->key, src->key);
	rev_edge->valid = FALSE;
	edge_attr->reverse_edge = graph_find_edge(graph, dst->key, src->key);
	edge_attr->reverse_edge->valid = FALSE;
	rev_edge_attr->reverse_edge = graph_find_edge(graph, src->key, dst->key);
}

/*
 * Iterate the incoming edges of a node and split them into two
 */

static char	*split_edge(void *parse_dst, void *data, const char *key)
{
	t_graph_node	*node;
	t_graph_edge	*edge;
	char			*src_key;
	char			*dst_key;
	t_size			i;

	node = data;
	i = 0;
	while (i < node->in.len)
	{
		edge = parr_get(&node->in, i);
		src_key = s_join(edge->u->key, "_out");
		dst_key = s_join(edge->v->key, "_in");
		if (!src_key || !dst_key)
			lem_exit_error("s_join");
		add_edges((t_graph *)parse_dst, src_key, dst_key);
		free(src_key);
		free(dst_key);
		i++;
	}
	return ((char *)key);
}

/*
 * Split a node into two nodes node_in and node_out and add them to the new
 * graph passed as a parameter. Add the original edges to the new nodes.
 */

static char	*split_node(void *parse_dst, void *data, const char *key)
{
	t_graph			*graph;
	t_graph_node	*node;
	t_node_attr		*in_node_attr;
	t_node_attr		*out_node_attr;

	graph = parse_dst;
	node = data;
	in_node_attr = lem_init_node_attr(s_join(key, "_in"),
			(t_coordinates){0, 0}, node);
	if (!in_node_attr)
		lem_exit_error("in node attr");
	out_node_attr = lem_init_node_attr(s_join(key, "_out"),
			(t_coordinates){0, 0}, node);
	if (!out_node_attr)
		lem_exit_error("out node attr");
	if (graph_add_node(graph, in_node_attr->name, in_node_attr) != 1
		|| graph_add_node(graph, out_node_attr->name, out_node_attr) != 1)
		lem_exit_error("add node");
	add_edges(graph, in_node_attr->name, out_node_attr->name);
	return ((char *)key);
}

/*
 *	Transform a directed graph into a vertex disjoint graph. This is done in
 *	two passes, first by splitting the nodes and then by splitting the edges.
 *	The splitting is done by passing the splitter functions to the map_parse
 *	iterator.
 */

t_lem	lem_transform_vertex_disjoint(t_lem *data)
{
	t_lem			transformed_data;
	char			*source_key;
	char			*sink_key;
	t_graph_node	*source;
	t_graph_node	*sink;

	transformed_data = lem_init_data();
	if (map_null(&transformed_data.graph))
		lem_exit_error("graph null");
	map_parse(&data->graph, &transformed_data.graph, split_node);
	map_parse(&data->graph, &transformed_data.graph, split_edge);
	source_key = s_join(data->s_key, "_out");
	sink_key = s_join(data->t_key, "_in");
	if (!source_key || !sink_key)
		lem_exit_error("s join");
	source = graph_find_node(&transformed_data.graph, source_key);
	sink = graph_find_node(&transformed_data.graph, sink_key);
	if (!source || !sink)
		lem_exit_error("source/sink");
	transformed_data.s_key = source->key;
	transformed_data.t_key = sink->key;
	free(source_key);
	free(sink_key);
	return (transformed_data);
}
