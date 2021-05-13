/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 20:53:32 by ksuomala          #+#    #+#             */
/*   Updated: 2021/05/10 16:52:08 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include <stdlib.h>

void	empty_rooms(t_room *rooms, char **moves, int *ant_locations)
{
	int i;
	int ant;

	i = 0;
	while (moves[i])
	{
		ant = ft_atoi(ft_strchr(moves[i], 'L') + 1);
		rooms[ant_locations[ant]].ant = 0;
		//ft_printf("L%d leaving room %d. Value set to %d", ant, ant_locations[ant], rooms[ant_locations[ant]].ant);
		i++;
	}
}

void	all_ants_in_end(int *ant_location)
{
	int ant;

	ant = 1;
	while (ant <= total_ants)
	{
		if (ant_location[ant] != total_rooms - 1)
			ft_printf("L%d did not make it to the end room. Got stuck in room %d\n", ant, ant_location[ant]);
		ant++;
	}
}

void	ants_moved(int *before, int *after)
{
	int i;

	i = 0;
	while (i <= total_ants)
	{
		if (before[i] && before[i] != total_rooms - 1 && before[i] == after[i])
			ft_printf("L%d Did not move from room %d\n", i, before[i]);
		i++;
	}
}

void	move_ants(char *line, t_room *rooms, int **ad_matrix, int *ant_locations)
{
	char	**move;
	int		ant_number;
	int		src;
	int		dst;
	int		i;

	i = 0;
	move = ft_strsplit(line, ' ');
	if (!move)
		error_exit("malloc failed in move_ants");
	empty_rooms(rooms, move, ant_locations);
	while (move[i])
	{
		ant_number = ft_atoi(move[i] + 1);
		src = ant_locations[ant_number];
		dst = name_to_index(rooms, ft_strchr(move[i], '-') + 1);
		if (!ad_matrix[src][dst])
			ft_printf("Tried to move L%d from %s-%s. Rooms are not connected\n",\
			 ant_number, rooms[src].name, rooms[dst].name);
		if (dst != total_rooms - 1 && rooms[dst].ant)
			ft_printf("L%d cannot move to %s. Room already has an ant.\n", ant_number, rooms[dst].name);
		rooms[src].ant = 0;
		rooms[dst].ant = ant_number;
		ant_locations[ant_number] = dst;
		i++;
	}
	ft_free2d((void**)move);
}

/*
** The goal is to check the following things:
** are the rooms connected?
** are the rooms free?
** are all ants moved on every line?
** are all ants moved from start-end?
*/

void	check_moves(char **input, t_room *rooms, int **ad_matrix)
{
	int i;
	int *ant_dst;
	int *ant_src;

	ant_src = ft_memalloc(sizeof(int) * (total_ants + 1));
	ant_dst = ft_memalloc(sizeof(int) * (total_ants + 1));
	if (!ant_src || !ant_dst)
		error_exit("malloc failed in check_moves");
	i = 0;
	while (ft_strcmp(input[i], ""))
		i++;
	i++;
	while (ft_strchr(input[i], 'L'))
	{
		ant_src = ft_memcpy((void*)ant_src, (void*)ant_dst, sizeof(int) * total_ants);
		move_ants(input[i], rooms, ad_matrix, ant_dst);
		ants_moved(ant_src, ant_dst);
		i++;
	}
	all_ants_in_end(ant_dst);
	free(ant_dst);
	free(ant_src);
}
