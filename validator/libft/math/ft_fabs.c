/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fabs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 10:35:52 by skoskine          #+#    #+#             */
/*   Updated: 2021/04/09 10:04:40 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long double	ft_fabsl(long double nbr)
{
	if (nbr < 0.0 || nbr == -0.0)
		return (-nbr);
	else
		return (nbr);
}

double	ft_fabs(double nbr)
{
	if (ft_isnegative(nbr))
		return (-nbr);
	else
		return (nbr);
}
