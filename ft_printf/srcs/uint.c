/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uint.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialleen <ialleen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 14:46:05 by ialleen           #+#    #+#             */
/*   Updated: 2019/10/09 20:01:58 by ialleen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int print_hhu(va_list *args, int *flags, size_t *p)
{
	int len;
	unsigned char output;
	int base;

	base = 10;
	flags[4] == 'o' ? base = 8 : 0;
	flags[4] == 'x' ? base = 16 : 0;
	flags[4] == 'X' ? base = 32 : 0;
	output = (unsigned char) va_arg(*args, void*);
	flags[4] == 'b' ? ft_putstr_index("0b", p, flags[9]) : 0;
	flags[4] == 'B' ? ft_putstr_index("0B", p, flags[9]) : 0;
	if (flags[4] == 'b' || flags[4] == 'B')
		return (ft_print_bin(sizeof(output), &output, 0, p));
	len = ft_uint_length(output, flags, base);
	flags[5] = (flags[1] > len) ? flags[1] : len;
	flags[2] > flags[5] ? (flags[5] = flags[2]) : 0;
	ft_align_uint(output, flags, len, p);
	return (1);
}

int print_hu(va_list *args, int *flags, size_t *p)
{
	int len;
	unsigned short output;
	int base;

	base = 10;
	flags[4] == 'o' ? base = 8 : 0;
	flags[4] == 'x' ? base = 16 : 0;
	flags[4] == 'X' ? base = 32 : 0;
	output = (unsigned short) va_arg(*args, void*);
	flags[4] == 'b' ? ft_putstr_index("0b", p, flags[9]) : 0;
	flags[4] == 'B' ? ft_putstr_index("0B", p, flags[9]) : 0;
	if (flags[4] == 'b' || flags[4] == 'B')
		return (ft_print_bin(sizeof(output), &output, 0, p));
	len = ft_uint_length(output, flags, base);
	flags[5] = (flags[1] > len) ? flags[1] : len;
	flags[2] > flags[5] ? (flags[5] = flags[2]) : 0;
	ft_align_uint(output, flags, len, p);
	return (1);
}

int print_lu(va_list *args, int *flags, size_t *p)
{
	int len;
	unsigned long output;
	int base;

	base = 10;
	flags[4] == 'o' ? base = 8 : 0;
	flags[4] == 'x' ? base = 16 : 0;
	flags[4] == 'X' ? base = 32 : 0;
	output = (unsigned long) va_arg(*args, void*);
	flags[4] == 'b' ? ft_putstr_index("0b", p, flags[9]) : 0;
	flags[4] == 'B' ? ft_putstr_index("0B", p, flags[9]) : 0;
	if (flags[4] == 'b' || flags[4] == 'B')
		return (ft_print_bin(sizeof(output), &output, 0, p));
	len = ft_uint_length(output, flags, base);
	flags[5] = (flags[1] > len) ? flags[1] : len;
	flags[2] > flags[5] ? (flags[5] = flags[2]) : 0;
	ft_align_uint(output, flags, len, p);
	return (1);
}

int print_llu(va_list *args, int *flags, size_t *p)
{
	int len;
	unsigned long long output;
	int base;

	base = 10;
	flags[4] == 'o' ? base = 8 : 0;
	flags[4] == 'x' ? base = 16 : 0;
	flags[4] == 'X' ? base = 32 : 0;
	output = (unsigned long long) va_arg(*args, void*);
	flags[4] == 'b' ? ft_putstr_index("0b", p, flags[9]) : 0;
	flags[4] == 'B' ? ft_putstr_index("0B", p, flags[9]) : 0;
	if (flags[4] == 'b' || flags[4] == 'B')
		return (ft_print_bin(sizeof(output), &output, 0, p));
	len = ft_uint_length(output, flags, base);
	flags[5] = (flags[1] > len) ? flags[1] : len;
	flags[2] > flags[5] ? (flags[5] = flags[2]) : 0;
	ft_align_uint(output, flags, len, p);
	return (1);
}

int print_u(va_list *args, int *flags, size_t *p)
{
	int len;
	unsigned int output;
	int base;

	base = 10;
	flags[4] == 'o' ? base = 8 : 0;
	flags[4] == 'x' ? base = 16 : 0;
	flags[4] == 'X' ? base = 32 : 0;
	output = (unsigned int) va_arg(*args, void*);
	flags[4] == 'b' ? ft_putstr_index("0b", p, flags[9]) : 0;
	flags[4] == 'B' ? ft_putstr_index("0B", p, flags[9]) : 0;
	if (flags[4] == 'b' || flags[4] == 'B')
		return (ft_print_bin(sizeof(output), &output, 0, p));
	len = ft_uint_length(output, flags, base);
	flags[5] = (flags[1] > len) ? flags[1] : len;
	flags[2] > flags[5] ? flags[5] = flags[2] : 0;
	ft_align_uint(output, flags, len, p);
	return (1);
}