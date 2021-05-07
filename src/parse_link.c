#include "lem_in.h"
#include "libft.h"

int	parse_link(t_graph *graph, char *line)
{
	char			*ptr;
	t_graph_node	*node_1;
	t_graph_node	*node_2;
	t_edge_attr		*attr;

	ptr = ft_strchr(line, '-');
	if (ptr == NULL)
		return (-1);
	*ptr = '\0';
	node_1 = graph_find_node(graph, line);
	node_2 = graph_find_node(graph, ptr + 1);
	if (node_1 == NULL || node_2 == NULL)
		return (-1);
	attr = init_edge_attr(1);
	if (attr == NULL || !graph_add_edge(graph, node_1->key, node_2->key, attr))
		return (-1);
	attr = init_edge_attr(1);
	if (attr == NULL || !graph_add_edge(graph, node_2->key, node_1->key, attr))
		return (-1);
	*ptr = '-';
	return (1);
}
