#include "libft.h"

void			ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*curr;

	curr = lst;
	while (curr != NULL)
	{
		f(curr);
		curr = curr->next;
	}
}
