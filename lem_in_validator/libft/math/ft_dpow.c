/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dpow.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 09:15:48 by skoskine          #+#    #+#             */
/*   Updated: 2021/04/09 10:00:08 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	ft_dpow(double base, int power)
{
	double	result;

	result = 1.0;
	while (power > 0)
	{
		result *= base;
		power--;
	}
	return (result);
}
