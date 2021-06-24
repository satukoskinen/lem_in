#include "../libft.h"
#include <fcntl.h>

int		main(void)
{
	int fd = open("p2_tests/putnbr_fd_user_output", O_CREAT | O_TRUNC | O_RDWR);
	if (fd != -1)
	{
	ft_putnbr_fd(0, fd);
	ft_putchar_fd('\n', fd);
	ft_putnbr_fd(1, fd);
	ft_putchar_fd('\n', fd);
	ft_putnbr_fd(-1, fd);
	ft_putchar_fd('\n', fd);
	ft_putnbr_fd(42, fd);
	ft_putchar_fd('\n', fd);
	ft_putnbr_fd(-42, fd);	
	ft_putchar_fd('\n', fd);
	ft_putnbr_fd(4000, fd);
	ft_putchar_fd('\n', fd);
	ft_putnbr_fd(-4000, fd);	
	ft_putchar_fd('\n', fd);
	ft_putnbr_fd(2147483647, fd);
	ft_putchar_fd('\n', fd);
	ft_putnbr_fd(-2147483648, fd);
	ft_putchar_fd('\n', fd);
	}
	ft_putnbr_fd(0, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(1, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(-1, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(42, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(-42, 1);	
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(4000, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(-4000, 1);	
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(2147483647, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(-2147483648, 1);
	ft_putchar_fd('\n', 1);
	return (0);
}