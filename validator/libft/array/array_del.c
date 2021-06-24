/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_del.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 22:24:46 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/28 12:26:35 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "array.h"

void	array_del(t_array **array)
{
	free((*array)->data);
	free(*array);
	*array = NULL;
}
