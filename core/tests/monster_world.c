#include <stdio.h>
#include <string.h>
#include "../inc/core.h"
#include "../graph/inc/graph.h"

# define NONE -1
# define NO_ATTR NULL
# define TRUE 1
# define FALSE 0
# define SOURCE -1
# define SINK -2

typedef struct		s_node_attr
{
	const char		*name;
}					t_node_attr;

typedef struct		s_edge_attr
{
	t_size			attributes;
}					t_edge_attr;

typedef struct s_monster_land
{
	t_graph		land;
	t_parray	names;
}				t_monster_land;

typedef struct	s_monster
{
	char		*name;
	t_size		index;
}				t_monster;

t_ssize print_edge(void *data, t_size i)
{
	t_graph_edge	*tmp;
	t_monster		*m1;
	t_monster		*m2;

	tmp = data;
	m1 = tmp->u->attr;
	m2 = tmp->v->attr;
	printf("%-30s=>    %-30s\n", m1->name, m2->name);
	return ((t_ssize)i);
}

t_ssize print_node(void *data, t_size i)
{
	t_graph_node	*tmp;
	t_monster		*monster;

	tmp = data;
	monster = tmp->attr;
	printf("%s\n", monster->name);
	// printf("In edges:\n");
	// arr_iter(&tmp->in, print_edge);
	// printf("Out edges:\n");
	// arr_iter(&tmp->out, print_edge);
	return (i);
}

t_ssize	free_node(void *data, t_size i)
{
	t_graph_node	*tmp;

	tmp = data;
	parr_free(&tmp->in);
	parr_free(&tmp->out);
	return (i);
}

char	*str_rand(t_size len)
{
	char	*dest;

	dest = s_new(len);
	char charset[] = "0123456789"
					"abcdefghijklmnopqrstuvwxyz"
					"ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	while (len-- > 0)
	{
		t_size index = (double) rand() / RAND_MAX * (sizeof charset - 1);
		*dest++ = charset[index];
	}
	*dest = '\0';
	return (dest);
}

t_monster	*new_monster(t_size i)
{
	t_monster	*new;

	new = (t_monster *)malloc(sizeof(t_monster));
	new->name = str_rand(10);
	new->index = i;
	return (new);
}

void
create_friendships(
	t_monster_land *monsters,
	t_size friendsip_ratio)
{
	t_monster	*monster;
	t_monster	*friend;
	char		*monster_name;
	char		*friend_name;
	t_size		i;
	t_size		j;

	i = 0;
	while (i < monsters->names.len)
	{
		monster_name = parr_get(&monsters->names, i);
		monster = map_get(&monsters->land, monster_name);
		j = 0;
		while (j < friendsip_ratio)
		{
			friend_name = parr_get(&monsters->names, rand() % monsters->names.len);
			if (s_cmp(friend_name, monster_name))
			{
				graph_add_edge(&monsters->land, monster_name, friend_name, NULL);
			}
			j++;
		}
		i++;
	}
}

t_monster_land
create_monster_land(
	t_size monster_count,
	t_size friendship_ratio)
{
	t_monster_land	monsters;
	t_monster		*monster;
	t_size			i;

	monsters.land = graph();
	monsters.names = parr(1);
	i = 0;
	while (i < monster_count)
	{
		monster = new_monster(i);
		graph_add_node(&monsters.land, monster->name, monster);
		parr_add(&monsters.names, monster->name, i);
		i++;
	}
	create_friendships(&monsters, friendship_ratio);
	return (monsters);
}

//-----------------------------------------------------------------------------

int main(void)
{
	t_monster_land	monsters;
	t_edges			breadth_first_search;
	t_edges			depth_first_search;
	t_nodes			shortest_path;
	char		*monster_king;

	monsters = create_monster_land(100, 3);
	monster_king = parr_get(&monsters.names, 6);
	printf("Monster King: %s\n", monster_king);

	depth_first_search = graph_dfs(&monsters.land, monster_king, NULL);
	printf("\nDepth First Search\n\n");
	parr_iter(&depth_first_search, print_edge);

	breadth_first_search = graph_bfs(&monsters.land, monster_king, NULL);
	printf("\nBreadth First Search\n\n");
	parr_iter(&breadth_first_search, print_edge);

	parr_free(&breadth_first_search);
	parr_free(&depth_first_search);
	parr_free(&shortest_path);
}
