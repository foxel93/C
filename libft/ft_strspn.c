/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialleen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 21:38:29 by ialleen           #+#    #+#             */
/*   Updated: 2019/09/03 22:10:15 by ialleen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strspn(const char *cs, const char *ct)
{
	size_t		n;
	const char	*tmp;

	n = 0;
	while (*cs)
	{
		tmp = ct;
		while (*tmp && *tmp != *cs)
			tmp++;
		if (!*tmp)
			break ;
		cs++;
		n++;
	}
	return (n);
}
