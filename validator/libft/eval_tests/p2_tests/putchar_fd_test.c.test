#include "../libft.h"
#include <fcntl.h>

int		main(void)
{
	int fd = open("p2_tests/putchar_fd_user_output", O_CREAT | O_TRUNC | O_RDWR);
	if (fd != -1)
	{
		ft_putchar_fd('a', fd);
		ft_putchar_fd('\n', fd);
		ft_putchar_fd(48, fd);
		ft_putchar_fd('\0', fd);
	}
	ft_putchar_fd('a', 1);
	ft_putchar_fd('\n', 1);
	ft_putchar_fd(48, 1);
	ft_putchar_fd('\0', 1);
	return (0);
}
