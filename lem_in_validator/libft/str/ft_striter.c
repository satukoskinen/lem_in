/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 14:59:24 by skoskine          #+#    #+#             */
/*   Updated: 2021/06/22 13:51:25 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	ft_striter(char *s, void (*f)(char *))
{
	t_size	i;

	i = 0;
	while (s != 0 && s[i] != '\0')
	{
		f(&s[i]);
		i++;
	}
}
