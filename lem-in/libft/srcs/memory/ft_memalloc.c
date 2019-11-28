#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*ptr;

	ptr = ft_safe_malloc(size);
	if (ptr != NULL)
	{
		ft_bzero(ptr, size);
		return (ptr);
	}
	return (NULL);
}
