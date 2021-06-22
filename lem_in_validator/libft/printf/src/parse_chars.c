/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 14:40:23 by skoskine          #+#    #+#             */
/*   Updated: 2021/06/22 13:51:25 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>

static char	*parse_str_result(t_data *specs, char *str, t_size str_len)
{
	t_size	result_len;
	t_size	i;
	t_size	j;
	char	*result;

	result_len = str_len + specs->min_field_width;
	result = (char *)malloc(sizeof(char) * (result_len + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	if (specs->min_field_width > 0 && !specs->zero_padding
		&& !specs->neg_field_width)
		i += add_padding(specs->min_field_width, ' ', &result[i]);
	else if (specs->min_field_width > 0 && specs->zero_padding
		&& !specs->neg_field_width)
		i += add_padding(specs->min_field_width, '0', &result[i]);
	j = 0;
	while (j < str_len)
		result[i++] = str[j++];
	if (specs->min_field_width > 0 && specs->neg_field_width)
		i += add_padding(specs->min_field_width, ' ', &result[i]);
	result[i] = '\0';
	return (result);
}

static t_size	update_str_specs(t_data *specs, char *str)
{
	t_size	len;

	if (str == NULL)
	{
		if (specs->has_precision && specs->precision < 6)
			len = specs->precision;
		else
			len = 6;
	}
	else
	{
		len = ft_strlen(str);
		if (specs->has_precision && specs->precision < len)
			len = specs->precision;
	}
	if (specs->min_field_width > len)
		specs->min_field_width = specs->min_field_width - len;
	else
		specs->min_field_width = 0;
	return (len);
}

int	parse_string(t_data *specs, char *str, char **result)
{
	t_size	str_len;

	str_len = update_str_specs(specs, str);
	if (str == NULL)
		*result = parse_str_result(specs, "(null)", str_len);
	else
		*result = parse_str_result(specs, str, str_len);
	if (*result == NULL)
		return (-1);
	else
		return (ft_strlen(*result));
}

int	parse_char(t_data *specs, char c, char **result)
{
	if (specs->min_field_width >= 1)
		specs->min_field_width--;
	*result = parse_str_result(specs, &c, 1);
	if (*result == NULL)
		return (-1);
	return (specs->min_field_width + 1);
}
