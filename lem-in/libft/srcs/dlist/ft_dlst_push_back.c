#include "libft.h"

_Bool ft_dlst_push_back(t_dlst *dlst, t_val value)
{
	t_node *tmp;

	tmp = malloc(sizeof(tmp));
	if (tmp == NULL)
		return (FALSE);
	tmp->value = value;
	tmp->next = NULL;
	tmp->prev = dlst->tail;
	if (dlst->tail)
		dlst->tail->next = tmp;
	dlst->tail = tmp;
	if (dlst->head == NULL)
		dlst->head = tmp;
	dlst->size++;
	return (TRUE);
}