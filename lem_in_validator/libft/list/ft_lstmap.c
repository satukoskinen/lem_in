/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 17:08:01 by skoskine          #+#    #+#             */
/*   Updated: 2021/04/09 10:01:58 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	ft_free_list(t_list **new)
{
	free((*new)->content);
	free(*new);
	*new = NULL;
}

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;

	new = f(lst);
	if (new == NULL)
		return (NULL);
	if (lst->next != NULL)
	{
		new->next = ft_lstmap(lst->next, f);
		if (new->next == NULL)
			ft_free_list(&new);
	}
	return (new);
}
