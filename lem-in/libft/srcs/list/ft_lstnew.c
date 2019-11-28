#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*result;

	result = ft_memalloc(sizeof(t_list));
	if (result == NULL)
		return (NULL);
	result->content = (void*)content;
	if (content == NULL)
		result->content_size = 0;
	else
		result->content_size = content_size;
	result->next = NULL;
	return (result);
}
