/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialleen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 10:33:20 by ialleen           #+#    #+#             */
/*   Updated: 2019/10/11 18:41:48 by ialleen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int			ft_vfprintf(int fd, const char **format, va_list *args)
{
	size_t	p;

	p = 0;
	while (**format != '\0')
	{
		if (**format == '%')
		{
			if (!parse_string(format, args, &p, fd))
				return (p);
		}
		else
		{
			ft_putchar_index(**format, &p, fd);
			(*format)++;
		}
	}
	return (p);
}

int			ft_printf(const char *format, ...)
{
	va_list	args;
	int		done;

	va_start(args, format);
	done = ft_vfprintf(1, &format, &args);
	va_end(args);
	return (done);
}
