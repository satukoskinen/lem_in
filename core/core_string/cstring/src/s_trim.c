/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_trim.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 01:30:47 by jkoskela          #+#    #+#             */
/*   Updated: 2021/05/11 09:05:49 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cstr.h"

char	*s_trim(char const *s)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;
	char			*str;

	i = 0;
	k = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (s[i] == '\0')
		return (s_cpy(malloc(sizeof(char) * 2), ""));
	j = s_len(s) - 1;
	while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
		j--;
	str = (char *)malloc(sizeof(char) * (j - i + 2));
	if (str == NULL)
		return (NULL);
	while (k < j - i + 1)
	{
		str[k] = s[i + k];
		k++;
	}
	str[k] = '\0';
	return (str);
}

/*
**  ----------------------------------------------------------------------------
**
**	S_trim
**
**	Allocates (with malloc(3)) and returns a copy of the string given as
**	argument without whitespaces at the beginning or at the end of the string.
**	Will be considered as whitespaces the following characters ’ ’, ’\n’ and
**	’\t’. If s has no whites- paces at the beginning or at the end, the
**	function returns a copy of s. If the allocation fails the function
**	returns NULL.
**
**  ----------------------------------------------------------------------------
*/
