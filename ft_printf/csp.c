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
	char	output;

	output = (char)va_arg(*args, int);
	ft_putchar(output);
	return (1);
}

int			spec_string(va_list *args, const int flags[5])
{
	char	*output;
	int		len;

	len = 6;
	output = va_arg(*args, char*);
	if (output != NULL)
		len = ft_strlen(output);
	else
		output = "(null)";
	ft_putstr("Here code\n");
	ft_putstr(output);
	return (1);
}

int			spec_pointer(va_list *args, const int flags[5])
{
	void			*output;
	unsigned long	address;
	int				len;

	len = 0;
	output = va_arg(*args, void*);
	address = (unsigned long)(output);
	ft_putstr("0x");
	ft_putadr(address, &len);
	return (1);
}

int			spec_per(void)
{
	ft_putchar('%');
	return (1);
}
