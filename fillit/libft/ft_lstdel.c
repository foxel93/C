/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialleen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 20:52:10 by ialleen           #+#    #+#             */
/*   Updated: 2019/09/13 11:45:46 by ialleen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*node;
	t_list	*next;

	if (del && alst && *alst)
	{
		node = *alst;
		while (node)
		{
			next = node->next;
			del(node->content, node->content_size);
			free(node);
			node = next;
		}
	}
	*alst = NULL;
}
