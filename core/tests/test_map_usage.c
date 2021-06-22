#include "../inc/core.h"

void	map_print(t_map *m)
{
	t_size	i;

	i = 0;
	while (i < m->capacity)
	{
		if (map_null_node(&m->node[i]))
			printf("[EMPTY]\n");
		else
			printf("%s\n", m->node[i].key);
		i++;
	}
}

int main(void)
{
	t_map	m;
	char	*course;

	m = map();
	course = NULL;
	map_add(&m, "Quantum Physics 1", "qp01");
	map_add(&m, "Quantum Physics 2", "qp02");
	map_add(&m, "Computer Science 1", "cs01");
	map_add(&m, "Computer Science 2", "cs02");
	map_add(&m, "Computer Science 3", "cs03");
	map_add(&m, "Computer Science 4", "cs04");
	map_add(&m, "Chemistry 1", "ch01");
	map_add(&m, "Chemistry 2", "ch02");
	map_add(&m, "Quantum Chromodynamics", "qd00");

	map_print(&m);
	course = map_get(&m, "cs01");
	printf("Course: %s\n", course);

	map_del(&m, "ch01");

	course = map_get(&m, "ch01");
	printf("Course: %s\n", course);

	course = map_get(&m, "cs03");
	printf("Course: %s\n", course);
}
