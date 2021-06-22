/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 12:54:27 by skoskine          #+#    #+#             */
/*   Updated: 2021/06/22 13:51:25 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, t_size len)
{
	t_size	src_len;

	src_len = ft_strlen(src);
	if (src_len >= len)
		return (ft_memcpy(dst, src, len));
	ft_memcpy(dst, src, src_len);
	ft_memset(&dst[src_len], 0, len - src_len);
	return (dst);
}
