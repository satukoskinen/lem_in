///////////////////////////////////////////////////////////////////////////////
///
/// \authors Julius Koskela
///
/// \brief Move memory
///
/// Memory move; copies `size` bytes from location `src` to location `dst`.
/// The two locations may overlap; the copy is always done in a non
/// destructive manner.
///
/// \param dst Pointer to destination memory.
/// \param src Pointer to source memory.
///	\param size Size of memory to be moved.
///
/// \return Pointer to destination memory.
///
///////////////////////////////////////////////////////////////////////////////

#include "../../../inc/core.h"

void	*mmove(void *dst, const void *src, t_size size)
{
	const t_byte	*src8;
	t_byte			*dst8;

	if (dst == NULL && src == NULL)
		return (NULL);
	dst8 = dst;
	src8 = src;
	if (dst8 < src8)
		mcpy(dst8, src8, size);
	else
		while (size--)
			*(dst8 + size) = *(src8 + size);
	return (dst8);
}
