#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	curr;

	i = 0;
	while (i < n)
	{
		curr = ((unsigned char*)src)[i];
		((unsigned char*)dst)[i] = curr;
		if (curr == (unsigned char)c)
			return ((void*)dst + i + 1);
		i++;
	}
	return (NULL);
}
