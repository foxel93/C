/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialleen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 17:27:53 by ialleen           #+#    #+#             */
/*   Updated: 2019/09/04 14:22:02 by ialleen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strtrim(char const *s)
{
	int		st;
	size_t	nd;
	char	*str;

	if (!s)
		return (NULL);
	st = 0;
	while (s[st] && ft_iswspace(s[st]))
		st++;
	nd = ft_strlen(&s[st]) - 1;
	while (s[st] && ft_iswspace(s[st + nd]))
		nd--;
	if (!(str = ft_strnew(nd + 1)))
		return (NULL);
	ft_strncpy(str, s + st, nd + 1);
	return (str);
}
