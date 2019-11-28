#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;

	if (!(ptr = (unsigned char *)malloc(sizeof(size) * count)))
		return (NULL);
	ft_memset(ptr, 0, count);
	return ((void *)ptr);
}