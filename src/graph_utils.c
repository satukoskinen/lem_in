#include "lem_in.h"
#include "libft.h"

t_edge_attr *init_edge_attr(int capacity)
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

t_node_attr	*init_node_attr(char *name, t_coordinates coordinates, t_graph_node *org)
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
	attr->coordinates = coordinates;
	attr->org = org;
	return (attr);
}

ssize_t print_edge(void *data, size_t i)
{
	t_graph_edge	*tmp;
	t_edge_attr		*attr;

	tmp = data;
	attr = tmp->attr;
	ft_printf("src %-5s -> dst %-5s flow %d capacity %d\n",
		tmp->src->key, tmp->dst->key, attr->flow, attr->capacity);
	return ((ssize_t)i);
}

ssize_t print_node(void *data, size_t i)
{
	t_graph_node	*tmp;
	t_node_attr		*attr;

	tmp = data;
	attr = tmp->attr;
	ft_printf("name %-5s key %-5s value %-5d\n",
		attr->name, tmp->key, attr->value);
	arr_iter(&tmp->in, print_edge);
	arr_iter(&tmp->out, print_edge);
	return ((ssize_t)i);
}
