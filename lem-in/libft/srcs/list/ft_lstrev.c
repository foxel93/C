#include "libft.h"

void	ft_lstrev(t_list **list)
{
	t_list	*curr;
	t_list	*prev;
	t_list	*next;

	curr = *list;
	prev = 0;
	while (curr)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	*list = prev;
}
