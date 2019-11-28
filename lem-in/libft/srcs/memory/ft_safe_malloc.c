#include "libft.h"

void	*ft_safe_malloc(size_t size)
{
	void	*ptr;

	if ((ptr = (void*)malloc(size)) == NULL)
	{
		ft_printf("ERROR\n");
		exit(EXIT_FAILURE);
	}
	return (ptr);
}
