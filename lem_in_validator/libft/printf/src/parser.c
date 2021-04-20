/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 21:28:28 by skoskine          #+#    #+#             */
/*   Updated: 2021/04/09 13:07:19 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include "libft.h"

static int	parse_conversion(t_data *specs, va_list *ap, char **result)
{
	int	ret;

	if (specs->conversion == '%')
		ret = parse_char(specs, '%', result);
	else if (specs->conversion == 'c')
		ret = parse_char(specs, va_arg(*ap, int), result);
	else if (specs->conversion == 's')
		ret = parse_string(specs, va_arg(*ap, char *), result);
	else if (specs->conversion == 'p')
		ret = parse_pointer(specs, va_arg(*ap, void *), result);
	else if (ft_strchr("di", specs->conversion))
		ret = parse_signed_ints(specs, ap, result);
	else if (ft_strchr("ouxX", specs->conversion))
		ret = parse_unsigned_ints(specs, ap, result);
	else if (ft_strchr("fF", specs->conversion))
		ret = parse_doubles(specs, ap, result);
	else
		ret = -1;
	return (ret);
}

static int	append_to_result(char **result, int ret, int len, const char *str)
{
	static int	arr_size = 100;

	if (*result == NULL)
	{
		*result = ft_memalloc(arr_size + 1);
		if (*result == NULL)
			return (-1);
	}
	if (ret + len > arr_size)
	{
		*result = ft_realloc(*result, arr_size, arr_size * 2 + len + 1);
		if (*result == NULL)
			return (-1);
		arr_size = arr_size * 2 + len;
	}
	ft_memcpy(&(*result)[ret], str, len);
	return (len);
}

int	parse_next_item(const char *format, va_list *ap, char **result, int len)
{
	t_data	conversion_specs;
	char	*conversion;
	int		ret;

	conversion = NULL;
	if (*format == '%')
	{
		ft_memset((void *)&conversion_specs, 0, sizeof(t_data));
		get_conversion_specs(&conversion_specs, format + 1);
		ret = parse_conversion(&conversion_specs, ap, &conversion);
		if (ret == -1)
			return (-1);
		ret = append_to_result(result, len, ret, conversion);
		ft_strdel(&conversion);
	}
	else
		ret = append_to_result(result, len, 1, format);
	return (ret);
}

int	format_item_length(const char *format)
{
	t_data	conversion_specs;
	int		i;

	i = 0;
	if (format[i] == '%')
		i = get_conversion_specs(&conversion_specs, &format[i + 1]) + 1;
	else
		i = 1;
	return (i);
}

int	parse(const char *format, va_list *ap, char **result)
{
	int		i;
	int		len;
	int		ret;

	i = 0;
	len = 0;
	ret = 0;
	while (format[i])
	{
		ret = parse_next_item(&format[i], ap, result, len);
		if (ret == -1)
			break ;
		len += ret;
		i += format_item_length(&format[i]);
	}
	if (ret == -1)
		return (-1);
	if (i == 0)
		*result = ft_strdup("");
	return (len);
}
