#include "libft.h"

_Bool ft_dlst_push_front(t_dlst *dlst, t_val value)
{
	t_node *tmp;

	tmp = malloc(sizeof(tmp));
	if (tmp == NULL)
		return (FALSE);
	tmp->value = value;
	tmp->next = dlst->head;
	tmp->prev = NULL;
	if (dlst->head)
		dlst->head->prev = tmp;
	dlst->head = tmp;
	if (dlst->tail == NULL)
		dlst->tail = tmp;
	dlst->size++;
	return (TRUE);
}