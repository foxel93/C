#include "libft.h"

_Bool ft_dlst_del_nth_elem(t_dlst *dlst, size_t index, t_val *value)
{
	t_node *elm;

	elm = ft_dlst_get_nth_elem(dlst, index);
	if (elm == NULL)
		return (FALSE);
	if (elm->prev)
		elm->prev->next = elm->next;
	if (elm->next)
		elm->next->prev = elm->prev;
	if (value != NULL)
		*value = elm->value;
	if (!elm->prev)
		dlst->head = elm->next;
	if (!elm->next)
		dlst->tail = elm->prev;
	free(elm);
	dlst->size--;
	return (TRUE);
}