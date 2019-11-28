/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialleen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 21:39:52 by ialleen           #+#    #+#             */
/*   Updated: 2019/09/03 21:41:50 by ialleen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strcspn(const char *s, const char *reject)
{
	size_t i;
	size_t i2;

	i = -1;
	while (s[++i] != '\0')
	{
		i2 = -1;
		while (reject[++i2] != '\0')
			if (s[i] == reject[i2])
				return (i);
	}
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
