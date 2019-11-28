#include "libft.h"

_Bool ft_dlst_add_nth_elem(t_dlst *dlst, size_t index, t_val value)
{
	t_node *elm;
	t_node *ins;

	elm = ft_dlst_get_nth_elem(dlst, index);
	if (elm == NULL)
		return (FALSE);
	ins = malloc(sizeof(ins));
	if (ins == NULL)
		return (FALSE);
	ins->value = value;
	ins->prev = elm;
	ins->next = elm->next;
	if (elm->next)
		elm->next->prev = ins;
	elm->next = ins;
	if (!elm->prev)
		dlst->head = elm;
	if (!elm->next)
		dlst->tail = elm;
	dlst->size++;
	return (TRUE);
}