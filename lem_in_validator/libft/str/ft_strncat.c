/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 13:20:52 by skoskine          #+#    #+#             */
/*   Updated: 2021/06/22 13:51:25 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, t_size n)
{
	t_size	s1_len;
	t_size	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (s2_len > n)
	{
		ft_memcpy(&s1[s1_len], s2, n);
		s1[s1_len + n] = '\0';
	}
	else
	{
		ft_memcpy(&s1[s1_len], s2, s2_len);
		s1[s1_len + s2_len] = '\0';
	}
	return (s1);
}
