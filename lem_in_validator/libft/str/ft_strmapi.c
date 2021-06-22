/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 15:21:10 by skoskine          #+#    #+#             */
/*   Updated: 2021/06/22 13:51:25 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*mapping;
	t_size	i;

	if (s == 0)
		return (NULL);
	mapping = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (mapping == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		mapping[i] = f(i, s[i]);
		i++;
	}
	mapping[i] = '\0';
	return (mapping);
}
