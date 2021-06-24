/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 09:38:51 by skoskine          #+#    #+#             */
/*   Updated: 2021/04/09 10:01:34 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long int	ln;

	ln = n;
	if (ln < 0)
		ft_putchar('-');
	if (ln >= 10)
		ft_putnbr(ln / 10);
	else if (ln <= -10)
		ft_putnbr(ln / 10 * (-1));
	if (ln >= 0)
		ft_putchar(ln % 10 + 48);
	else
		ft_putchar((ln * (-1)) % 10 + 48);
}
