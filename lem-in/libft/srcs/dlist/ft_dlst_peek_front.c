#include "libft.h"

_Bool ft_dlst_peek_front(t_dlst *dlst, t_val *value)
{
	if (dlst == NULL || dlst->head == NULL)
		return (FALSE);
	*value = dlst->head->value;
	return (TRUE);
}