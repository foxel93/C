/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uint.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialleen <ialleen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 14:46:05 by ialleen           #+#    #+#             */
/*   Updated: 2019/10/06 14:54:47 by ialleen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int 	print_hhu(va_list *args, const int flags[5])
{
	int len;
	unsigned char output;
	int width;
    int base;

    base = 10;
	flags[4] == 'o' ? base = 8 : 0;
    flags[4] == 'x' ? base = 16 : 0;
    flags[4] == 'X' ? base = 32 : 0;
	output = (unsigned char)va_arg(*args, void*);
    flags[4] == 'b' ? ft_putstr("0b") : 0;
    flags[4] == 'B' ? ft_putstr("0B") : 0;
    if (flags[4] == 'b' || flags[4] == 'B')
        return (printBits(sizeof(output), &output, 0));
    len = ft_uint_length(output, flags, base);
    flags[1] > len ? (width = flags[1]) : (width = len);
    flags[2] > width ? (width = flags[2]) : 0;
    ft_align_uint(output, flags, width, len);
	return (1);
}

int 	print_hu(va_list *args, const int flags[5])
{
	int len;
	unsigned short output;
	int width;
    int base;

    base = 10;
    flags[4] == 'o' ? base = 8 : 0;
    flags[4] == 'x' ? base = 16 : 0;
    flags[4] == 'X' ? base = 32 : 0;
	output = (unsigned short)va_arg(*args, void*);
    flags[4] == 'b' ? ft_putstr("0b") : 0;
    flags[4] == 'B' ? ft_putstr("0B") : 0;
    if (flags[4] == 'b' || flags[4] == 'B')
        return (printBits(sizeof(output), &output, 0));
    len = ft_uint_length(output, flags, base);
    flags[1] > len ? (width = flags[1]) : (width = len);
    flags[2] > width ? (width = flags[2]) : 0;
    ft_align_uint(output, flags, width, len);
	return (1);
}

int 	print_lu(va_list *args, const int flags[5])
{
	int len;
	unsigned long output;
	int width;
    int base;

    base = 10;
    flags[4] == 'o' ? base = 8 : 0;
    flags[4] == 'x' ? base = 16 : 0;
    flags[4] == 'X' ? base = 32 : 0;
	output = (unsigned long)va_arg(*args, void*);
    flags[4] == 'b' ? ft_putstr("0b") : 0;
    flags[4] == 'B' ? ft_putstr("0B") : 0;
    if (flags[4] == 'b' || flags[4] == 'B')
        return (printBits(sizeof(output), &output, 0));
    len = ft_uint_length(output, flags, base);
    flags[1] > len ? (width = flags[1]) : (width = len);
    flags[2] > width ? (width = flags[2]) : 0;
    ft_align_uint(output, flags, width, len);
	return (1);
}

int 	print_llu(va_list *args, const int flags[5])
{
	int len;
	unsigned long long output;
	int width;
    int base;

    base = 10;
    flags[4] == 'o' ? base = 8 : 0;
    flags[4] == 'x' ? base = 16 : 0;
    flags[4] == 'X' ? base = 32 : 0;
	output = (unsigned long long)va_arg(*args, void*);
	flags[4] == 'b' ? ft_putstr("0b") : 0;
    flags[4] == 'B' ? ft_putstr("0B") : 0;
    if (flags[4] == 'b' || flags[4] == 'B')
        return (printBits(sizeof(output), &output, 0));
    len = ft_uint_length(output, flags, base);
    flags[1] > len ? (width = flags[1]) : (width = len);
    flags[2] > width ? (width = flags[2]) : 0;
    ft_align_uint(output, flags, width, len);
	return (1);
}

int 	print_u(va_list *args, const int flags[5])
{
	int len;
	unsigned int output;
	int width;
    int base;

    base = 10;
    flags[4] == 'o' ? base = 8 : 0;
    flags[4] == 'x' ? base = 16 : 0;
    flags[4] == 'X' ? base = 32 : 0;
	output = (unsigned int)va_arg(*args, void*);
    flags[4] == 'b' ? ft_putstr("0b") : 0;
    flags[4] == 'B' ? ft_putstr("0B") : 0;
    if (flags[4] == 'b' || flags[4] == 'B')
        return (printBits(sizeof(output), &output, 0));
    len = ft_uint_length(output, flags, base);
    flags[1] > len ? (width = flags[1]) : (width = len);
    flags[2] > width ? (width = flags[2]) : 0;
    ft_align_uint(output, flags, width, len);
	return (1);
}