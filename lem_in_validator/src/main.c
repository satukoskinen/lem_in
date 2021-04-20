#include "lem_in_validator.h"
#include "libft.h"

int	error(char *msg, int return_value)
{
	ft_dprintf(2, "%s", msg);
	return (return_value);
}

int	main(void)
{
	t_graph	*graph;
	int		ant_count;

	graph = graph_new();
	if (graph == NULL)
		return (error("Error occurred\n", -1));
	if (parse_input(graph) != 1)
		return (error("Error parsing input\n", 1));
	ant_count = graph->source->value;
	if (validate_output(graph, ant_count) == 1)
		ft_printf("OK\n");
	else
		return (error("Error\n", 1));
	return (0);
}
