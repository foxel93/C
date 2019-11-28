#include "libft.h"

static void	memcpy_backward(void *dst, const void *src, size_t num)
{
	size_t	i;

	if (num == 0)
		return ;
	i = num - 1;
	while (1)
	{
		((unsigned char*)dst)[i] = ((unsigned char*)src)[i];
		if (i == 0)
			return ;
		i--;
	}
}

void		*ft_memmove(void *dst, const void *src, size_t num)
{
	if (dst < src)
		ft_memcpy(dst, src, num);
	else
		memcpy_backward(dst, src, num);
	return (dst);
}
