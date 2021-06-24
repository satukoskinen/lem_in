#include "lem_in_validator.h"
#include "libft.h"
#include <stdlib.h>

static void	free_str_array(char **arr)
{
	size_t	i;

	if (arr == NULL)
		return ;
	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	arr = NULL;
}

static t_vertex	*check_current_vertex(int ant, t_array *adj_list)
{
	t_vertex	*vertex;
	t_vertex	*source;
	size_t		i;

	source = NULL;
	i = 0;
	while (i < array_size(adj_list))
	{
		vertex = *(t_vertex **)array_get(adj_list, i);
		if (vertex->is_source)
			source = vertex;
		if (vertex->value == ant)
			return (vertex);
		i++;
	}
	if (source != NULL)
		return (source);
	else
		return (NULL);
}

static int	check_vertex(char *id, t_graph *graph, int ant)
{
	t_vertex	*current;
	t_vertex	*dst;

	dst = graph_get_vertex(graph, id);
	if (dst == NULL)
		return (error("Destination vertex not found\n", 0));
	if (dst->value != 0)
		return (error("Destination vertex not empty\n", 0));
	current = check_current_vertex(ant, dst->adj_list);
	if (current == NULL)
		return (error("Ant's current vertex not found \
				from current's adjacent vertices\n", 0));
	if (current->is_source)
	{
		if (current->value != ant)
			return (error("Wrong ant taken from source\n", 0));
		current->value = ant + 1;
	}
	else
	{
		current->value = 0;
	}
	if (!dst->is_sink)
		dst->value = ant;
	return (1);
}

static int	check_move(char *move, t_graph *graph, int *ant_moved, int ants)
{
	int			ant;
	size_t		j;

	j = 0;
	if (move[j] != 'L')
		return (error("Missing 'L'\n", 0));
	j++;
	ant = ft_atoi(&move[j]);
	if (!(ant >= 1 && ant <= ants))
		return (error("Invalid ant number\n", 0));
	if (ant_moved[ant])
		return (error("Ant moved twice\n", 0));
	ant_moved[ant] = 1;
	while (ft_isdigit(move[j]))
		j++;
	if (move[j] != '-')
		return (error("Missing '-'\n", 0));
	j++;
	return (check_vertex(&move[j], graph, ant));
}

int	validate_round(char *line, t_graph *graph, int ants)
{
	char		**moves;
	size_t		i;
	int			ret;
	int			*ant_moved;

	moves = ft_strsplit(line, ' ');
	if (moves == NULL)
		return (-1);
	ant_moved = (int *)ft_calloc(ants + 1, sizeof(int));
	if (ant_moved == NULL)
		return (-1);
	i = 0;
	while (moves[i] != NULL)
	{
		ret = check_move(moves[i], graph, ant_moved, ants);
		if (ret != 1)
			break ;
		i++;
	}
	free_str_array(moves);
	return (ret);
}
