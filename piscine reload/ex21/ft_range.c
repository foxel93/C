/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialleen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 14:40:53 by ialleen           #+#    #+#             */
/*   Updated: 2019/09/02 14:52:48 by ialleen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			*ft_range(int min, int max)
{
	int		len;
	int		*res;
	int		*tmp;

	if (min >= max)
		return (NULL);
	len = max - min;
	if (!(res = (int *)malloc(sizeof(int) * len)))
		return (NULL);
	tmp = res;
	while (min < max)
		*res++ = min++;
	return (tmp);
}
