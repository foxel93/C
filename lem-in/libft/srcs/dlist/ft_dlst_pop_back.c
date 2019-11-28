#include "libft.h"

_Bool ft_dlst_pop_back(t_dlst *dlst, t_val *value)
{
	t_node *next;

	if (dlst == NULL || dlst->tail == NULL)
		return (FALSE);
	next = dlst->tail;
	dlst->tail = dlst->tail->prev;
	if (dlst->tail)
		dlst->tail->next = NULL;
	if (next == dlst->head)
		dlst->head = NULL;
	*value = next->value;
	free(next);
	dlst->size--;
	return (TRUE);
}