#include "libft.h"

void	ft_lst_del(t_list **lst)
{
	if (*lst != NULL && (*lst)->content != NULL)
	{
		if ((*lst)->next != NULL && (*lst)->next->content != NULL)
			ft_lst_del(&((*lst)->next));
		ft_lst_del_one((*lst), (*lst)->content, (*lst)->content_size);
	}
}
