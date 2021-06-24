/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 23:19:00 by skoskine          #+#    #+#             */
/*   Updated: 2021/04/09 10:00:28 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_sqrt(double value)
{
	double	sqrt;

	sqrt = value * 0.5;
	while (sqrt * sqrt > value)
		sqrt *= 0.5;
	while (sqrt * sqrt < value)
		sqrt *= 1.25;
	while (sqrt * sqrt > value)
		sqrt *= 0.875;
	while (sqrt * sqrt < value)
		sqrt *= 1.0625;
	while (sqrt * sqrt > value)
		sqrt *= 1 - 0.03125;
	while (sqrt * sqrt < value)
		sqrt *= 1.015625;
	return (sqrt);
}
