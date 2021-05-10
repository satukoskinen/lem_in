#include "lem_in.h"

t_graph_edge	*get_edge(t_graph_node *src, t_graph_node *dst)
{
	size_t			i;
	t_graph_edge	*edge;

	i = 0;
	while (i < src->out.len)
	{
		edge = arr_get(&src->out, i);
		if (s_cmp(edge->dst->key, dst->key) == 0)
			return (edge);
		i++;
	}
	return (NULL);
}

t_edge_attr	*init_edge_attr(int capacity)
{
	t_edge_attr	*attr;

	attr = (t_edge_attr *)malloc(sizeof(t_edge_attr));
	if (attr == NULL)
		return (NULL);
	attr->flow = 0;
	attr->capacity = capacity;
	attr->reverse_edge = NULL;
	return (attr);
}

t_node_attr	*init_node_attr(
	char *name,
	t_coordinates coords,
	t_graph_node *org)
{
	t_node_attr	*attr;

	attr = (t_node_attr *)malloc(sizeof(t_node_attr));
	if (attr == NULL)
		return (NULL);
	attr->name = s_dup(name);
	if (attr->name == NULL)
	{
		free(attr);
		return (NULL);
	}
	if (g_node_id > INT32_MAX)
	{
		printf("Too many nodes!!!\n");
		exit(-1);
	}
	attr->value = 0;
	attr->coordinates = coords;
	attr->org = org;
	return (attr);
}

t_graph	init_graph(void)
{
	t_graph			graph;
	t_graph_attr	*attr;

	attr = (t_graph_attr *)malloc(sizeof(t_graph_attr));
	if (attr == NULL)
		return (CR_GRAPH_NULL);
	attr->sink = NULL;
	attr->source = NULL;
	graph = graph_new(attr);
	return (graph);
}
