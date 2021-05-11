#include "lem_in.h"

t_edge_attr	*lem_init_edge_attr(int capacity)
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
