/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 20:02:29 by ksuomala          #+#    #+#             */
/*   Updated: 2021/05/10 16:54:00 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef struct	s_room
{
	char	*name;
	int		ant;
}				t_room;

int			total_rooms;
int			total_ants;

void		create_rooms(char **input, t_room **room_array);
int			**create_matrix(char **input, t_room *room_array);
void		check_moves(char **input, t_room *rooms, int **ad_matrix);
void		error_exit(char *str);
int			name_to_index(t_room *array, char *name);
void	ft_free2d(void **input);





