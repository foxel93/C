#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnewchar(void const *content, size_t content_size)
{
	t_list	*new;

	if ((new = (t_list*)ft_memalloc(sizeof(t_list))) == NULL)
		return (NULL);
	if (content == NULL)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		new->content = NULL;
		if ((new->content = ft_strdup(content)) == NULL)
		{
			free(new);
			return (NULL);
		}
		new->content_size = content_size;
	}
	new->next = NULL;
	return (new);
}
