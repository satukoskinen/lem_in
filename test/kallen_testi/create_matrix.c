/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuomala <ksuomala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 20:08:10 by ksuomala          #+#    #+#             */
/*   Updated: 2021/04/28 13:43:03 by ksuomala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int		name_to_index(t_room *array, char *name)
{
	int i;

	i = 0;
	while (ft_strcmp(array[i].name, name))
		i++;
	return (i);
}

void	add_edge(int **matrix, char *line, t_room *room_array)
{
	char	**split;
	int		src_room;
	int		dst_room;

	split = ft_strsplit(line, '-');
	src_room = name_to_index(room_array, split[0]);
	dst_room = name_to_index(room_array, split[1]);
	matrix[src_room][dst_room] = 1;
	matrix[dst_room][src_room] = 1;
	ft_free2d((void**)split);
}

int		**create_matrix(char **input, t_room *room_array)
{
	int		i;
	int		j;
	int		**ad_matrix;

	i = 0;
	j = -1;
	while (!ft_strchr(input[i], '-'))
		i++;
	ad_matrix = ft_memalloc(sizeof(int*) * (total_rooms + 1));
	if (!ad_matrix)
		error_exit("malloc failed in create_matrix");
	while (++j < total_rooms)
	{
		ad_matrix[j] = ft_memalloc(sizeof(int) * total_rooms);
		if (!ad_matrix[j])
			error_exit("malloc failed in create_matrix");
	}
	while(ft_strchr(input[i], '-'))
		add_edge(ad_matrix, input[i++], room_array);
	return (ad_matrix);
}
