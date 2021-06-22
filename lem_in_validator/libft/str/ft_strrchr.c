/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 14:03:40 by skoskine          #+#    #+#             */
/*   Updated: 2021/06/22 13:51:25 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	t_size	s_len;

	s_len = ft_strlen(s);
	while (s_len > 0)
	{
		if (s[s_len] == c)
			return ((char *)&s[s_len]);
		s_len--;
	}
	if (s[s_len] == c)
		return ((char *)&s[s_len]);
	return (NULL);
}
