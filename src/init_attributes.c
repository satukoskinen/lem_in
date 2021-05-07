#include "lem_in.h"
#include "libft.h"

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

t_node_attr	*init_node_attr(char *name, t_coordinates coords, t_graph_node *org)
{
	t_node_attr	*attr;

	attr = (t_node_attr *)malloc(sizeof(t_node_attr));
	if (attr == NULL)
		return (NULL);
	attr->name = ft_strdup(name);
	if (attr->name == NULL)
	{
		free(attr);
		return (NULL);
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
