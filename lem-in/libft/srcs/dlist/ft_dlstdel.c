#include "libft.h"

void ft_dlstdel(t_dlst **dlst)
{
	t_node *tmp;
	t_node *next;

	if (dlst == NULL || *dlst == NULL)
		return ;
	tmp = (*dlst)->head;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	free(*dlst);
	(*dlst) = NULL;
}