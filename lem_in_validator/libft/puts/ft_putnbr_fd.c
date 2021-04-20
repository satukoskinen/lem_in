/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 18:52:09 by skoskine          #+#    #+#             */
/*   Updated: 2021/04/09 10:01:44 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	ln;

	ln = n;
	if (ln < 0)
		ft_putchar_fd('-', fd);
	if (ln >= 10)
		ft_putnbr_fd(ln / 10, fd);
	else if (ln <= -10)
		ft_putnbr_fd(ln / 10 * (-1), fd);
	if (ln >= 0)
		ft_putchar_fd(ln % 10 + 48, fd);
	else
		ft_putchar_fd((ln * (-1)) % 10 + 48, fd);
}
