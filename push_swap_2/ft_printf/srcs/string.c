/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialleen <ialleen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 16:19:29 by ialleen           #+#    #+#             */
/*   Updated: 2019/10/11 16:24:26 by ialleen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static void	ft_align_string(char *str, int *flags, size_t *p)
{
	int		i;
	char	c;

	i = 0;
	if (flags[0] & F_M)
	{
		while (i < flags[2])
			ft_putchar_index(str[i++], p, flags[9]);
		while (flags[5]-- > 0)
			ft_putchar_index(' ', p, flags[9]);
	}
	else
	{
		while (flags[5]-- > 0)
		{
			c = (flags[0] & F_Z) ? '0' : ' ';
			ft_putchar_index(c, p, flags[9]);
		}
		while (i < flags[2])
			ft_putchar_index(str[i++], p, flags[9]);
	}
}

int			spec_string(va_list *args, int *flags, size_t *p)
{
	char	*output;
	int		len;

	output = va_arg(*args, char*);
	output == NULL ? output = "(null)" : 0;
	len = ft_strlen(output);
	flags[2] >= len ? flags[2] = len : 0;
	if (flags[1] > flags[2])
		flags[5] = flags[1];
	else if (flags[1] != -1)
		flags[5] = flags[1];
	if (len == 0)
		flags[2] = 0;
	else if (flags[2] < len)
	{
		if (flags[2] == -2)
			flags[2] = len;
		else if (flags[2] == -1)
			flags[2] = 0;
	}
	else if (flags[2] >= len)
		flags[2] = len;
	flags[5] -= flags[2];
	ft_align_string(output, flags, p);
	return (1);
}
