#include "../libft.h"
#include <fcntl.h>

int		main(void)
{
	int fd = open("p2_tests/putendl_fd_user_output", O_CREAT | O_TRUNC | O_RDWR);
	if (fd != -1)
	{
		ft_putendl_fd("test string\n", fd);
		ft_putendl_fd("\t", fd);
		ft_putendl_fd("", fd);
	}
	ft_putendl_fd("test string\n", 1);
	ft_putendl_fd("\t", 1);
	ft_putendl_fd("", 1);
	return (0);
}
