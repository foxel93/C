#include "libft.h"

t_dlst* ft_dlstnew(void)
{
	t_dlst *tmp;

	tmp = malloc(sizeof(tmp));
	if (tmp == NULL)
		return (NULL);
	tmp->size = 0;
	tmp->head = NULL;
	tmp->tail = NULL;
	return (tmp);
}