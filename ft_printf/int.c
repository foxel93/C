/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialleen <ialleen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 12:27:39 by ialleen           #+#    #+#             */
/*   Updated: 2019/10/06 14:33:53 by ialleen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int 	print_hhd(va_list *args, const int flags[5])
{
	int len;
	char output;
	int width;

	output = (char)va_arg(*args, void*);
	len = ft_int_length(output, flags[0]);
	flags[1] > len ? (width = flags[1]) : (width = len);
	ft_allign_int(output, flags[0], width, len);
	return (0);
}

int 	print_hd(va_list *args, const int flags[5])
{
	int len;
	short output;
	int width;

	output = (short)va_arg(*args, void*);
	len = ft_int_length(output, flags[0]);
	flags[1] > len ? (width = flags[1]) : (width = len);
	ft_allign_int(output, flags[0], width, len);
	return (0);
}

int 	print_ld(va_list *args, const int flags[5])
{
	int len;
	long output;
	int width;

	output = (long)va_arg(*args, void*);
	len = ft_int_length(output, flags[0]);
	flags[1] > len ? (width = flags[1]) : (width = len);
	ft_allign_int(output, flags[0], width, len);
	return (0);
}

int 	print_lld(va_list *args, const int flags[5])
{
	int len;
	long long output;
	int width;

	output = (long long)va_arg(*args, void*);
	len = ft_int_length(output, flags[0]);
	flags[1] > len ? (width = flags[1]) : (width = len);
	ft_allign_int(output, flags[0], width, len);
	return (0);
}

int 	print_d(va_list *args, const int flags[5])
{
	int len;
	int output;
	int width;

	output = (int)va_arg(*args, void*);
	len = ft_int_length(output, flags[0]);
	flags[1] > len ? (width = flags[1]) : (width = len);
	ft_allign_int(output, flags[0], width, len);
	return (0);
}