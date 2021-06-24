#include "libft.h"
#include "get_next_line.h"
#include <stdlib.h>

/*
** Deletes the node corresponding to fd from the remainder list. If it is
** the only node, it is deleted and remainder list is set to NULL.
*/

void	delete_remainder(int fd, t_rlist **r_list)
{
	t_rlist	*p;
	t_rlist	*temp;

	p = *r_list;
	if (p != 0 && p->next == NULL && p->fd == fd)
	{
		free(*r_list);
		*r_list = NULL;
	}
	else if (p != 0 && p->fd == fd)
	{
		*r_list = p->next;
		free(p);
	}
	else if (p != 0 && p->next != 0)
	{
		while (p->next->fd != fd)
			p = p->next;
		if (p->next->fd == fd)
		{
			temp = p->next->next;
			free(p->next);
			p->next = temp;
		}
	}
}

/*
**
*/

static t_rlist	*create_node(int fd, char **input)
{
	t_rlist	*p;

	p = (t_rlist *)malloc(sizeof(t_rlist));
	if (p == NULL)
		return (NULL);
	p->fd = fd;
	p->remainder = *input;
	p->next = NULL;
	return (p);
}

/*
** Saves the given input to the remainder node corresponding to fd.
** If no node exists for the fd (or no list has yet been created),
** that is created and either added to end of existing list or saved
** as head of a new list.
*/

int	update_remainder(int fd, char **input, t_rlist **r_list)
{
	t_rlist	*p;
	t_rlist	*prev;

	p = *r_list;
	prev = NULL;
	while (p != NULL)
	{
		if (p->fd == fd)
		{
			p->remainder = *input;
			return (1);
		}
		prev = p;
		p = p->next;
	}
	p = create_node(fd, input);
	if (p == NULL)
		return (-1);
	if (prev != NULL)
		prev->next = p;
	else
		*r_list = p;
	return (1);
}

/*
** Checks whether something has been saved as a remainder from a
** previous call of get_next_line on this fd. If so, that is saved
** to **line.
*/

int	read_remainder(int fd, t_rlist *r_list, char **temp)
{
	t_rlist	*p;
	int		ret;

	p = r_list;
	while (p != NULL)
	{
		if (p->fd == fd && p->remainder != NULL)
		{
			ret = add_input(fd, p->remainder, &r_list, temp);
			ft_strdel(&(p->remainder));
			return (ret);
		}
		p = p->next;
	}
	return (0);
}
