/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lin_usage.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 00:30:42 by jkoskela          #+#    #+#             */
/*   Updated: 2021/05/19 12:51:31 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/core.h"

static t_ssize	parse_vec(t_array *dst, t_parray *src)
{
	t_vec4	curr;
	t_size	i;

	i = 0;
	while (i < src->len - 10)
	{
		curr.v[0] = atof(parr_get(src, i));
		curr.v[1] = atof(parr_get(src, i + 1));
		curr.v[2] = atof(parr_get(src, i + 2));
		curr.v[3] = atof(parr_get(src, i + 3));
		arr_add_last(dst, &curr);
		i += 4;
	}
	return (i);
}

static t_ssize	deallocate_str(void *data, t_size i)
{
	free(data);
	return (i);
}

void	transform(t_array *buffer)
{
	t_mat4	scale;
	t_vec4	*cast;
	t_size	i;

	scale = lin_m4_transform(100);
	lin_m4_print(&scale);
	cast = (t_vec4 *)buffer->data;
	i = 0;
	while (i < buffer->len)
	{
		cast[i] = lin_m4xv4_r(&scale, &cast[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_parray	file;
	t_array	buffer;

	if (argc != 2)
		return (0);
	file = parr(1);
	buffer = arr(sizeof(t_vec4));
	parr_read_file(&file, argv[1]);
	parse_vec(&buffer, &file);
	transform(&buffer);
	arr_iter(&buffer, lin_v4_print);
	parr_iter(&file, deallocate_str);
	parr_free(&file);
	arr_free(&buffer);
}
