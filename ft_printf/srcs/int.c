/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialleen <ialleen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 12:27:39 by ialleen           #+#    #+#             */
/*   Updated: 2019/10/09 20:01:58 by ialleen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int print_hhd(va_list *args, int *flags, size_t *p)
{
	int len;
	char output;
	int width;

	output = (char) va_arg(*args, void*);
	len = ft_int_length(output, flags);
	width = (flags[1] > len) ? flags[1] : len;
	flags[2] > width ? (width = flags[2]) : 0;
	flags[5] = width;
	ft_align_int(output, flags, len, p);
	return (1);
}

int print_hd(va_list *args, int *flags, size_t *p)
{
	int len;
	short output;
	int width;

	output = (short) va_arg(*args, void*);
	len = ft_int_length(output, flags);
	width = (flags[1] > len) ? flags[1] : len;
	flags[2] > width ? (width = flags[2]) : 0;
	flags[5] = width;
	ft_align_int(output, flags, len, p);
	return (1);
}

int print_ld(va_list *args, int *flags, size_t *p)
{
	int len;
	long output;
	int width;

	output = (long) va_arg(*args, void*);
	len = ft_int_length(output, flags);
	width = (flags[1] > len) ? flags[1] : len;
	flags[2] > width ? (width = flags[2]) : 0;
	flags[5] = width;
	ft_align_int(output, flags, len, p);
	return (1);
}

int print_lld(va_list *args, int *flags, size_t *p)
{
	int len;
	long long output;
	int width;

	output = (long long) va_arg(*args, void*);
	len = ft_int_length(output, flags);
	width = (flags[1] > len) ? flags[1] : len;
	flags[2] > width ? (width = flags[2]) : 0;
	flags[5] = width;
	ft_align_int(output, flags, len, p);
	return (1);
}

int print_d(va_list *args, int *flags, size_t *p)
{
	int len;
	int output;
	int width;

	output = (int) va_arg(*args, void*);
	len = ft_int_length(output, flags);
	width = (flags[1] > len) ? flags[1] : len;
	flags[2] > width ? (width = flags[2]) : 0;
	flags[5] = width;
	ft_align_int(output, flags, len, p);
	return (1);
}