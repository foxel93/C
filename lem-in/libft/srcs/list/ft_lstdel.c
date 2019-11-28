#include "libft.h"

void			ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*curr;
	t_list	*next;

	curr = *alst;
	while ((curr) != NULL)
	{
		next = (curr)->next;
		ft_lstdelone(&curr, del);
		curr = next;
	}
	*alst = NULL;
}
