/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialleen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 21:33:36 by ialleen           #+#    #+#             */
/*   Updated: 2019/09/03 21:36:03 by ialleen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strtok(char *str, const char sep)
{
	static char		*stock = NULL;
	char			*ptr;
	int				flg;

	flg = 0;
	ptr = NULL;
	if (str != NULL)
		stock = ft_strdup(str);
	while (*stock != '\0')
	{
		if (flg == 0 && *stock != sep)
		{
			flg = 1;
			ptr = stock;
		}
		else if (flg == 1 && *stock == sep)
		{
			*stock = '\0';
			stock += 1;
			break ;
		}
		stock += 1;
	}
	return (ptr);
}
