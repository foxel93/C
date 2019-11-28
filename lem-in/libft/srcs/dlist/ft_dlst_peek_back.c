#include "libft.h"

_Bool ft_dlst_peek_back(t_dlst *dlst, t_val *value)
{
	if (dlst == NULL || dlst->tail == NULL)
		return (FALSE);
	*value = dlst->tail->value;
	return (TRUE);
}