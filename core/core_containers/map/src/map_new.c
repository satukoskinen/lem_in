/******************************************************************************
 * \authors
 * \brief
 * \param
 * \return
 *****************************************************************************/

#include "../../../inc/core.h"

t_map	map_new(void)
{
	t_map	m;
	t_size	i;

	m.capacity = CR_MAP_START_CAPACITY;
	m.load_factor = CR_MAP_LOAD_FACTOR;
	m.hash = map_hash_1;
	m.probe = map_probe_linear;
	m.resize = map_resize_linear;
	m.node = (t_map_node *)minit(sizeof(t_map_node) * m.capacity);
	if (!m.node)
	{
		print("Allocation failed in function: map!\n");
		exit(-1);
	}
	i = 0;
	while (i < m.capacity)
	{
		m.node[i] = (t_map_node){NULL, NULL};
		i++;
	}
	m.count = 0;
	return (m);
}
