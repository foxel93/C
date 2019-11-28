/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialleen <ialleen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 14:38:52 by ialleen           #+#    #+#             */
/*   Updated: 2019/10/11 16:27:45 by ialleen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putstr_index(char *str, size_t *p, int fd)
{
	size_t	i;

	i = 0;
	while (str[i] != 0)
		i++;
	*p += i;
	write(fd, str, i);
	return (0);
}
