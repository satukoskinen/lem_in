/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 13:25:41 by skoskine          #+#    #+#             */
/*   Updated: 2021/04/09 09:58:13 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdlib.h>

int	ft_dprintf(int fd, const char *format, ...)
{
	va_list	ap;
	char	*result;
	int		ret;

	result = NULL;
	va_start(ap, format);
	ret = ft_vasprintf(&result, format, ap);
	va_end(ap);
	if (ret != -1)
	{
		if (write(fd, result, ret) == -1)
			ret = -1;
	}
	free(result);
	return (ret);
}
