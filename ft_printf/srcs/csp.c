/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   csp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialleen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 10:28:03 by ialleen           #+#    #+#             */
/*   Updated: 2019/10/10 18:54:59 by ialleen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"



static void ft_align_string(char *str, int *flags, size_t *p)
{
	int i;
	char c;

	i = 0;
	if (flags[0] & F_M)
	{
		while (i < flags[2])
			ft_putchar_index(str[i++], p, flags[9]);
		while (flags[5]-- > 0)
		{
			ft_putchar_index(' ', p, flags[9]);
		}
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

int spec_char(va_list *args, int *flags, size_t *p)
{
	unsigned char output;
	int	width;
	char c;

	output = (unsigned char) va_arg(*args, int);
	if (flags[1] > 0)
		width = flags[1] - 1;
	else
		width = 0;
	if (flags[0] & F_M)
	{
		write(flags[9], &output, 1);
		(*p)++;
		while (width--)
			ft_putchar_index(' ', p, flags[9]);
	}
	else
	{
		c = (flags[0] & F_Z) ? '0' : ' ';
		while (width--)
			ft_putchar_index(c, p, flags[9]);
		write(flags[9], &output, 1);
		(*p)++;
	}
	return (1);
}

int spec_string(va_list *args, int *flags, size_t *p)
{
	char *output;
	int len;

	output = va_arg(*args, char*);
	output == NULL ? output = "(null)" : 0;
	len = ft_strlen(output);
	flags[2] > len ? flags[2] = len : 0;
	printf("%d\n", flags[2]);
	flags[5] = (flags[1] > len) ? flags[1] : len;
	printf("%d\n", flags[5]);
	if (len == 0)
		flags[2] = 0;
	/*else if (flags[2] < len)
	{
		if (flags[2] == -2)
			flags[2] = len;
		else if (flags[2] == -1)
			flags[2] = 0;
	}*/
	/*else if (flags[2] >= len)
		flags[2] = len;*/
	flags[5] -= flags[2];
	printf("%d\n", flags[5]);
	ft_align_string(output, flags, p);
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

