/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   csp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialleen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 10:28:03 by ialleen           #+#    #+#             */
/*   Updated: 2019/10/06 11:02:08 by ialleen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			spec_char(va_list *args, const int flags[5])
{
	unsigned char	output;

	output = (unsigned char)va_arg(*args, int);
	write(1, &output, 1);
	return (1);
}

int			spec_string(va_list *args, const int flags[5])
{
	char	*output;

	output = va_arg(*args, char*);
	output == NULL ? ft_putstr("(null)") : ft_putstr(output);
	return (1);
}

int			spec_pointer(va_list *args, int flags[5])
{
	void			*output;
	unsigned long	address;
	int				len;
    int width;

	output = va_arg(*args, void*);
	address = (unsigned long)(output);
    flags[4] = 'x';
    flags[0] |= F_H;
    flags[0] |= F_S;
    len = ft_uint_length(address, flags, 16);
    flags[1] > len ? (width = flags[1]) : (width = len);
    flags[2] > width ? (width = flags[2]) : 0;

    ft_align_uint(address, flags, width, len);
	return (1);
}

int			spec_per(void)
{
	ft_putchar('%');
	return (1);
}
