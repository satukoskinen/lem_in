/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_readline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 00:32:25 by jkoskela          #+#    #+#             */
/*   Updated: 2021/06/09 15:49:57 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cstr.h"

static int	eof(char **raw, char **line, int r)
{
	if (r == 0 && *raw[0] != '\0')
	{
		*line = *raw;
		return (2);
	}
	else
	{
		s_del(&*raw);
		return (0);
	}
}

static int	readbuf(char **raw, char **line, int fd)
{
	char	*tmp;
	char	buff[READLINE_MAX_BUFF + 1];
	int		r;

	r = read(fd, buff, READLINE_MAX_BUFF);
	while (r > 0)
	{
		buff[r] = '\0';
		tmp = s_join(*raw, buff);
		s_del(&*raw);
		if (!(s_chr(buff, '\n')))
			*raw = tmp;
		else
		{
			*line = s_cdup(tmp, '\n');
			*raw = s_csub(buff, '\n');
			free(tmp);
			return (1);
		}
		r = read(fd, buff, READLINE_MAX_BUFF);
	}
	if (r == -1)
		return (-1);
	return (eof(&*raw, &*line, r));
}

int	s_readline(const int fd, char **line)
{
	static char	*raw[READLINE_MAX_FD];
	char		*tmp;

	if (fd < 0 || line == NULL)
		return (-1);
	if (!raw[fd])
		raw[fd] = s_new(0);
	if ((s_chr(raw[fd], '\n')))
	{
		*line = s_cdup(raw[fd], '\n');
		tmp = s_csub(raw[fd], '\n');
		s_del(&raw[fd]);
		raw[fd] = tmp;
		return (1);
	}
	return (readbuf(&raw[fd], &*line, fd));
}

/*
**  ----------------------------------------------------------------------------
**
**	S_READLINE
**
**	Read a line from a file and put the line into the string `line` passed
**	by reference. Subsequent calls to the function will get the next line
**	untill end of file or if file descriptor is closed.
**
**  ----------------------------------------------------------------------------
*/
