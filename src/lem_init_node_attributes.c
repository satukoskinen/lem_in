#include "lem_in.h"

/*
 *	Initialize node attributes. Name is assumed to have been dynamically
 *	allocated.
 */

t_node_attr	*lem_init_node_attr(
	char *name,
	t_coordinates coords,
	t_graph_node *org)
{
	t_node_attr	*attr;

	if (name == NULL)
		return (NULL);
	attr = (t_node_attr *)malloc(sizeof(t_node_attr));
	if (attr == NULL)
		return (NULL);
	attr->name = name;
	attr->value = 0;
	attr->coordinates = coords;
	attr->org = org;
	return (attr);
}
