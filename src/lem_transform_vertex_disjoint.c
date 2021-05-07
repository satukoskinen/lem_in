/*******************************************************************************
 *
 * \authors Satu Koskinen, Julius Koskela
 *
 * \brief Create a vertex disjoint transformation of a graph.
 *
 * \param src Source graph.
 *
 * \return A new transformed graph.
 *
 ******************************************************************************/

#include "../lem_in.h"

// MOVE TO LIB!!

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

char	*map_parse(
	t_map *src,
	void *dst,
	char *(*f)(void *, void *, const char *key))
{
	t_map_node	node;
	size_t		i;

	i = 0;
	while (i < src->capacity)
	{
		if (!map_null_node(&src->node[i]))
		{
			node = src->node[i];
			if (!(f(dst, node.data, node.key)))
				return ((char *)node.key);
		}
		i++;
	}
	return ((char *)node.key);
}

/*******************************************************************************
 *
 ******************************************************************************/

static ssize_t	reverse_edge(
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
	edge_attr = init_edge_attr(1);
	rev_edge_attr = init_edge_attr(0);
	graph_add_edge(new, dst->key, src->key, edge_attr);
	graph_add_edge(new, src->key, dst->key, rev_edge_attr);
	edge_attr->reverse_edge = graph_find_edge(new, src->key, dst->key);
	rev_edge_attr->reverse_edge = graph_find_edge(new, dst->key, src->key);
	return (1);
}

/*******************************************************************************
 *
 ******************************************************************************/

static char	*split_edge(void *parse_dst, void *data, const char *key)
{
	t_graph			*dst;
	t_graph_node	*node;
	t_graph_edge	*edge;
	size_t			j;

	node = data;
	dst = parse_dst;
	j = 0;
	while (j < node->in.len)
	{
		edge = arr_get(&node->in, j);
		reverse_edge(dst,
			s_join(edge->src->key, "_in"),
			s_join(edge->dst->key, "_out"));
		j++;
	}
	return ((char *)key);
}

/*******************************************************************************
 *
 ******************************************************************************/

static char	*split_node(void *parse_dst, void *data, const char *key)
{
	t_graph			*graph;
	t_graph_node	*node;
	t_node_attr		*in_node_attr;
	t_node_attr		*out_node_attr;

	graph = parse_dst;
	node = data;
	in_node_attr = init_node_attr(
		s_join(key, "_in"), (t_coordinates){0, 0}, node);
	out_node_attr = init_node_attr(
		s_join(key, "_out"), (t_coordinates){0, 0}, node);
	graph_add_node(graph, in_node_attr->name, in_node_attr);
	graph_add_node(graph, out_node_attr->name, out_node_attr);
	reverse_edge(graph, in_node_attr->name, out_node_attr->name);
	return ((char *)key);
}

/*******************************************************************************
 *
 ******************************************************************************/

t_graph	lem_transform_vertex_disjoint(t_graph *src)
{
	t_graph			new;

	new = graph_new(NULL);
	map_parse(&src->data, &new, split_node);
	map_parse(&src->data, &new, split_edge);
	return (new);
}
