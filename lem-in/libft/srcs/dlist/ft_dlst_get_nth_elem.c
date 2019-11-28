#include "libft.h"

t_node* ft_dlst_get_nth_elem(t_dlst *dlst, size_t index)
{
	t_node *tmp;
	size_t	i;

	if (dlst == NULL)
		return (NULL);
	if (index < dlst->size/2)
	{
		i = -1;
		tmp = dlst->head;
		while (tmp && ++i < index)
			tmp = tmp->next;
	}
	else
	{
		i = dlst->size;
		tmp = dlst->tail;
		while (tmp && --i > index)
			tmp = tmp->prev;
	}
	return (tmp);
}