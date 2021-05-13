/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_rooms.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuomala <ksuomala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 19:46:28 by ksuomala          #+#    #+#             */
/*   Updated: 2021/04/27 21:19:43 by ksuomala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

t_room		add_room(char *line)
{
	char	**split;
	t_room	new_room;

	split = ft_strsplit(line, ' ');
	new_room.name = ft_strdup(split[0]);
	if (!new_room.name)
		error_exit("malloc failed in add_room");
	new_room.ant = 0;
	ft_free2d((void**)split);
	return (new_room);
}

void		create_rooms(char **input, t_room **room_array)
{
	int		i;
	int		len;
	t_room	last_room;

	len = 10000;
	total_rooms = 1;
	*room_array = ft_memalloc(sizeof(t_room) * len);
	i = 0;
	while (ft_strcmp(input[i], ""))
	{
		if (ft_strstr(input[i], "##start"))
			room_array[0][0] = add_room(input[++i]);
		else if (ft_strstr(input[i], "##end"))
			last_room = add_room(input[++i]);
		else if (ft_strchr(input[i], ' '))
			room_array[0][total_rooms++] = add_room(input[i]);
		i++;
	}
	room_array[0][total_rooms++] = last_room;
}
