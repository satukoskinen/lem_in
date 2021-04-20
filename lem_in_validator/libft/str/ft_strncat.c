/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 13:20:52 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/24 21:17:26 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	s1_len;
	size_t	s2_len;

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
