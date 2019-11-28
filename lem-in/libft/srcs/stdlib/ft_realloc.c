#include "libft.h"
#include <stdlib.h>

void	*ft_realloc(void *ptr, size_t size)
{
	char	*newptr;
	size_t	ptrsize;

	if (ptr == 0)
		return (ft_memalloc(size));
	ptrsize = sizeof(ptr);
	if (size <= ptrsize)
		return (ptr);
	if ((newptr = (char*)ft_memalloc(ptrsize
					* (ft_strlen((char*)ptr) + size))) == NULL)
		return (NULL);
	if ((ft_memcpy(newptr, ptr, ft_strlen((char*)ptr))) == NULL)
		return (ptr);
	free(ptr);
	return (newptr);
}
