/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 17:16:18 by skoskine          #+#    #+#             */
/*   Updated: 2021/06/22 13:51:25 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	count_strings(char const *s, char c)
{
	int		string_count;
	t_size	i;

	string_count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			string_count++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (string_count);
}

static t_size	next_word_length(char const *s, char c)
{
	t_size	len;

	len = 0;
	while (s[len] != c && s[len] != '\0')
		len++;
	return (len);
}

static char	**free_char_arr(char **arr, int size)
{
	while (size > 0)
	{
		free(arr[size - 1]);
		size--;
	}
	free(arr);
	return (NULL);
}

char	*add_next_str(char const *s, char c)
{
	t_size	len;
	char	*str;

	len = next_word_length(s, c);
	str = ft_strsub(s, 0, len);
	return (str);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**arr;
	int		j;
	int		word_count;

	if (s == 0)
		return (NULL);
	word_count = count_strings(s, c);
	arr = (char **)malloc(sizeof(*arr) * (word_count + 1));
	if (arr == NULL)
		return (NULL);
	j = 0;
	while (j < word_count)
	{
		while (*s == c)
			s++;
		arr[j] = add_next_str(s, c);
		if (arr[j] == NULL)
			return (free_char_arr(arr, j - 1));
		s += ft_strlen(arr[j]);
		j++;
	}
	arr[j] = NULL;
	return (arr);
}
