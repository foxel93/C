#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t num)
{
	size_t i;

	if (dst == src)
		return (dst);
	i = -1;
	while (++i < num)
		((unsigned char*)dst)[i] = ((unsigned char*)src)[i];
	return (dst);
}
