#include "libft.h"

_Bool ft_dlst_pop_front(t_dlst *dlst, t_val *value)
{
	t_node *prev;

	if (dlst->head == NULL)
		return (FALSE);
	prev = dlst->head;
	dlst->head = dlst->head->next;
	if (dlst->head)
		dlst->head->prev = NULL;
	if (prev == dlst->tail)
		dlst->tail = NULL;
	*value = prev->value;
	free(prev);
	dlst->size--;
	return (TRUE);
}