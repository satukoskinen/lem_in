#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

typedef struct s_rlist
{
	int				fd;
	char			*remainder;
	struct s_rlist	*next;
}					t_rlist;

int		add_input(int fd, char *input, t_rlist **r_list, char **temp);
int		read_remainder(int fd, t_rlist *r_list, char **temp);
int		update_remainder(int fd, char **input, t_rlist **r_list);
void	delete_remainder(int fd, t_rlist **r_list);

#endif
