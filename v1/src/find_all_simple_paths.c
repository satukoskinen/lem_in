#include "lem_in.h"
#include "libft.h"

/*
  comment
  here
  yes
 */

t_array	*copy_path_to_array(t_array **paths, t_array *current_path)
{
	t_array	*new;
	size_t	i;

	new = array_new(array_size(current_path), sizeof(t_vertex *));
	if (new == NULL)
		return (NULL);
	i = array_size(current_path);
	while (i > 0)
	{
		array_add(&new, array_get(current_path, i - 1));
		i--;
	}
	insert_path_to_array(paths, &new);
	return (*paths);
}

void	DFS(t_graph *graph, t_vertex *u, t_vertex *v, t_array **paths, t_array *current_path)
{
	size_t		i;
	t_edge		*adj_edge;
	t_vertex	*next;

	if (u->dist == 1)
		return ;
	u->dist = 1;
	array_add(&current_path, &u);
	if (ft_strcmp(u->id, v->id) == 0)
	{
		copy_path_to_array(paths, current_path);
		u->dist = 0;
		array_remove(current_path, array_size(current_path) - 1);
		return ;
	}
	i = 0;
	while (i < array_size(u->adj_list))
	{
		adj_edge = *(t_edge **)array_get(u->adj_list, i);
		next = adj_edge->dst;
		DFS(graph, next, v, paths, current_path);
		i++;
	}
	array_remove(current_path, array_size(current_path) - 1);
	u->dist = 0;
}

void	set_vertices_dist(t_graph *graph, int value)
{
	size_t		i;
	t_vertex	*vertex;

	i = 0;
	while (i < array_size(graph->vertices))
	{
		vertex = *(t_vertex **)array_get(graph->vertices, i);
		vertex->dist = value;
		i++;
	}
}

t_array	*find_all_simple_paths(t_graph *graph, t_vertex *src, t_vertex *dst)
{
	t_array	*paths;
	t_array	*current_path;

	paths = array_new(INIT_SIZE, sizeof(t_array *));
	if (paths == NULL)
		return (NULL);
	current_path = array_new(graph->vertex_count, sizeof(t_vertex *));
	if (current_path == NULL)
	{
		array_del(&paths);
		return (NULL);
	}
	set_vertices_dist(graph, 0);
	DFS(graph, src, dst, &paths, current_path);
	return (paths);
}
