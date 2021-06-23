///////////////////////////////////////////////////////////////////////////////
///
/// \authors Julius Koskela
///
/// \brief Rotate a dynamic array.
///
/// Number of rotations passed as a parameter. A negative number rotates the
/// array counter-clockwise, positive clockwise. 0 does nothing.
///
/// \param src Source array.
/// \param steps Amount of rotations.
///
/// \return 1 on success 0 on failure.
///
///////////////////////////////////////////////////////////////////////////////

#include "../inc/array.h"

static t_ssize	rot(t_array *src, t_ssize steps)
{
	void	*tmp;
	t_ssize	i;

	tmp = malloc(src->elem_size);
	steps = steps * -1LLU;
	i = 0;
	while (i < steps)
	{
		tmp = arr_take_first(tmp, src);
		arr_add_last(src, tmp);
		i++;
	}
	free(tmp);
	return (i);
}

static t_ssize	rrot(t_array *src, t_ssize steps)
{
	void	*tmp;
	t_ssize	i;

	tmp = malloc(src->elem_size);
	i = 0;
	while (i < steps)
	{
		tmp = arr_take_last(tmp, src);
		arr_add_first(src, tmp);
		i++;
	}
	free(tmp);
	return (i);
}

t_ssize	arr_rotate(t_array *src, t_ssize steps)
{
	if (src->len < 2 || steps == 0)
		return (0);
	if (steps > 0)
		rrot(src, steps);
	else if (steps < 0)
		rot(src, steps);
	return (CR_SUCCESS);
}
