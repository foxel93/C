#include "libft.h"
#include <stdlib.h>

void	ft_lstadd_last(t_list **alst, t_list *n)
{
	t_list *cur;

	if (alst && n)
	{
		if (*alst == NULL)
		{
			(*alst) = n;
			(*alst)->next = NULL;
		}
		else if ((*alst)->content == NULL)
		{
			free(*alst);
			*alst = n;
			(*alst)->next = NULL;
		}
		else
		{
			cur = *alst;
			while (cur->next != NULL)
				cur = cur->next;
			cur->next = n;
		}
	}
}
