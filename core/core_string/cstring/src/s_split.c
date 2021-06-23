/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_split.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 01:30:32 by jkoskela          #+#    #+#             */
/*   Updated: 2021/05/11 09:05:34 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cstr.h"

static int	ft_cntwrd(char const *s, char c)
{
	unsigned int	i;
	int				cntr;

	i = 0;
	cntr = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			cntr++;
		while (s[i] && (s[i] != c))
			i++;
	}
	return (cntr);
}

static char	**ft_splitaux(char const *s, char c, char **tab)
{
	int				i;
	int				j;
	int				k;

	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > j)
		{
			tab[k] = s_ndup(s + j, i - j);
			if (!tab[k])
				return (NULL);
			k++;
		}
	}
	tab[k] = NULL;
	return (tab);
}

char	**s_split(char const *s, char c)
{
	char			**tab;

	tab = (char **)malloc(sizeof(char *) * (ft_cntwrd(s, c)) + 1);
	if (tab == NULL)
		return (NULL);
	tab = ft_splitaux(s, c, tab);
	return (tab);
}

/*
**  ----------------------------------------------------------------------------
**
**	S_split
**
**	Split the string `s` by the delimiting character `c` into an array of
**	strings `tab`.
**
**	Returns an array of strings.
**
**  ----------------------------------------------------------------------------
*/
