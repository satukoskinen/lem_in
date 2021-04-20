#include "../libft.h"
#include <fcntl.h>

int		main(void)
{
	int fd = open("p2_tests/putstr_fd_user_output", O_CREAT | O_TRUNC | O_RDWR);
	if (fd != -1)
	{
		ft_putstr_fd("test string\n", fd);
		ft_putstr_fd("\t", fd);
		ft_putstr_fd("", fd);
	}
	ft_putstr_fd("test string\n", 1);
	ft_putstr_fd("\t", 1);
	ft_putstr_fd("", 1);
	return (0);
}
