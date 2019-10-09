/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialleen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 10:33:20 by ialleen           #+#    #+#             */
/*   Updated: 2019/10/09 20:01:58 by ialleen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"


int ft_printf(const char *format, ...)
{
	va_list args;
	size_t p;
	int fd = 1;

	p = 0;
	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			if (!parse_string(&format, &args, &p, fd))
				return (p);
		} else
			ft_putchar_index(*format++, &p, fd);
	}
	va_end(args);
	return (p);
}
