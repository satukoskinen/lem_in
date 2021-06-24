/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 12:30:58 by skoskine          #+#    #+#             */
/*   Updated: 2021/04/11 12:09:41 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

/*
** Saves given input to **line, but only until a possible '\n'. If a newline
** is encountered, the remainder after that is saved to the remainder list.
*/

int	add_input(int fd, char *input, t_rlist **r_list, char **line)
{
	char	*p;
	char	*remainder;
	char	*new;

	remainder = NULL;
	p = ft_strchr(input, '\n');
	if (p != NULL)
	{
		*p = '\0';
		if (*(p + 1) != '\0')
			remainder = ft_strdup(p + 1);
		if (*(p + 1) != '\0' && remainder == NULL)
			return (-1);
	}
	new = ft_strjoin(*line, input);
	if (new == NULL)
		return (-1);
	free(*line);
	*line = new;
	if (remainder != NULL)
		return (update_remainder(fd, &remainder, r_list));
	else
		return ((p != NULL));
}

/*
**
*/

static int	check_remainder(t_rlist *r_list, int fd, char **line, int *ret)
{
	*ret = 0;
	if (r_list != NULL)
		*ret = read_remainder(fd, r_list, line);
	return (*ret);
}

/*
**
*/

static int	read_to_buf(int fd, char *buf)
{
	int	bytes_read;

	bytes_read = read(fd, buf, BUFF_SIZE);
	if (bytes_read == -1)
		return (-1);
	buf[bytes_read] = '\0';
	return (bytes_read);
}

/*
** Reads a line that ends either with newline '\n' or end-of-file EOF
** from the file descriptor fd and saves it in pointer to character **line.
** Possible return values are 1, 0, -1 according to whether a line has been
** read, reading has been completed (EOF reached) or whether an error occurred.
*/

int	get_next_line(const int fd, char **line)
{
	int				ret;
	int				bytes_read;
	char			buf[BUFF_SIZE + 1];
	static t_rlist	*r_list;

	if (fd < 0 || line == NULL)
		return (-1);
	*line = NULL;
	if (check_remainder(r_list, fd, line, &ret) != 0)
		return (ret);
	bytes_read = 1;
	while (bytes_read != 0 && ret == 0)
	{
		bytes_read = read_to_buf(fd, (char *)buf);
		if (bytes_read == -1 || bytes_read == 0)
			break ;
		ret = add_input(fd, buf, &r_list, line);
	}
	if (bytes_read == 0)
		delete_remainder(fd, &r_list);
	if (bytes_read == 0 && *line == NULL)
		return (0);
	else if (bytes_read == -1 || ret == -1)
		return (-1);
	return (1);
}
