#include "lem_in.h"

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
	attr->value = 0;
	attr->coordinates = coords;
	attr->org = org;
	return (attr);
}
