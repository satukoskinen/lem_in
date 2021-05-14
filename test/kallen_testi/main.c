/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 19:31:34 by ksuomala          #+#    #+#             */
/*   Updated: 2021/05/10 16:53:44 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include <stdlib.h>

void	ft_free2d(void **input)
{
	size_t	i;

	i = 0;
	while (input[i])
	{
		free(input[i]);
		i++;
	}
	free(input);
}

void		error_exit(char *str)
{
	ft_dprintf(2, "%s\n", str);
	exit(0);
}

char		**input_realloc(char **input, int len)
{
	char **tmp;

	tmp = ft_memalloc(sizeof(char*) * (len * 2 + 1));
	tmp = ft_memcpy(tmp, input, sizeof(char*) * len);
	free(input);
	return (tmp);
}

char	**parse_input(void)
{
	char	**input;
	char	*line;
	int		len;
	int		i;

	i = 0;
	len = 20000;
	input = ft_memalloc(sizeof(char*) * (len + 1));
	if (!input)
		error_exit("malloc failed in parse_input");
	while (get_next_line(0, &line))
	{
		if (i == len)
		{
			input = input_realloc(input, len);
			len += len;
		}
		input[i] = line;
		i++;
	}
	return (input);
}


int main(void)
{
	t_room	*rooms;
	char	**input;
	int		**ad_matrix;
	int		i;

	rooms = NULL;
	input = parse_input();
	total_ants = ft_atoi(input[0]);
	create_rooms(input, &rooms);
	//ft_putnbr(total_rooms);
	//ft_n(1);
	//ft_putnbr(ants);
	//ft_n(1);
	ad_matrix = create_matrix(input, rooms);
	check_moves(input, rooms, ad_matrix);
	//int i = 0;

	//while (rooms[i].name)
	//{
	//	ft_putendl(rooms[i].name);
//		i++;
//	}
//	int ii = -1;
//	while (ad_matrix[++ii])
//	{
//		while (i < total_rooms)
//			ft_printf("|%2d", ad_matrix[ii][i++]);
//		i = 0;
//		ft_n(1);
//	}
	ft_free2d((void**)input);
	ft_free2d((void**)ad_matrix);
	i = -1;
	while (++i < total_rooms)
		ft_strdel(&rooms[i].name);
	ft_memdel((void**)&rooms);
	ft_printf("DONE\n");
}
