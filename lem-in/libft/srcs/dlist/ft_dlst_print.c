#include "libft.h"

void ft_dlst_print(t_dlst *list, void (*f)(t_val value))
{
	t_node *tmp;

	tmp = list->head;
	while (tmp)
	{
		f(tmp->value);
		tmp = tmp->next;
	}
}