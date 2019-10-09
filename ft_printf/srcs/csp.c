/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   csp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialleen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 10:28:03 by ialleen           #+#    #+#             */
/*   Updated: 2019/10/09 20:19:09 by ialleen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int spec_char(va_list *args, int *flags, size_t *p)
{
	unsigned char output;

	output = (unsigned char) va_arg(*args, int);
	write(flags[9], &output, 1);
	(*p)++;
	return (1);
}

int spec_string(va_list *args, int *flags, size_t *p)
{
	char *output;

	output = va_arg(*args, char*);
	if (output == NULL)
		ft_putstr_index("(null)", p, flags[9]);
	else
		ft_putstr_index(output, p, flags[9]);
	return (1);
}

int spec_pointer(va_list *args, int *flags, size_t *p)
{
	void *output;
	unsigned long address;
	int len;

	output = va_arg(*args, void*);
	address = (unsigned long) (output);
	flags[4] = 'x';
	flags[0] |= F_H;
	flags[0] |= F_S;
	len = ft_uint_length(address, flags, 16);
	flags[5] = (flags[1] > len) ? flags[1] : len;
	flags[2] > flags[5] ? flags[5] = flags[2] : 0;
	ft_align_uint(address, flags, len, p);
	return (1);
}

int spec_per(int *flags, size_t *p)
{
	if ((flags[0] & F_M) == F_M)
		ft_putchar_index('%', p, flags[9]);
	while (flags[1]-- > 1)
		ft_putchar_index(' ', p, flags[9]);
	if ((flags[0] & F_M) != F_M)
		ft_putchar_index('%', p, flags[9]);
	return (1);
}
