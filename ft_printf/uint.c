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

	output = (unsigned char)va_arg(*args, void*);
	len = ft_int_length(output, 0);
	flags[1] > len ? (width = flags[1]) : (width = len);
	ft_allign_uint(output, flags[0], width, len);
	return (0);
}

int 	print_hu(va_list *args, const int flags[5])
{
	int len;
	unsigned short output;
	int width;

	output = (unsigned short)va_arg(*args, void*);
	len = ft_int_length(output, 0);
	flags[1] > len ? (width = flags[1]) : (width = len);
	ft_allign_uint(output, flags[0], width, len);
	return (0);
}

int 	print_lu(va_list *args, const int flags[5])
{
	int len;
	unsigned long output;
	int width;

	output = (unsigned long)va_arg(*args, void*);
	len = ft_int_length(output, 0);
	flags[1] > len ? (width = flags[1]) : (width = len);
	ft_allign_uint(output, flags[0], width, len);
	return (0);
}

int 	print_llu(va_list *args, const int flags[5])
{
	int len;
	unsigned long long output;
	int width;

	output = (unsigned long long)va_arg(*args, void*);
	len = ft_int_length(output, 0);
	flags[1] > len ? (width = flags[1]) : (width = len);
	ft_allign_uint(output, flags[0], width, len);
	return (0);
}

int 	print_u(va_list *args, const int flags[5])
{
	int len;
	unsigned int output;
	int width;

	output = (unsigned int)va_arg(*args, void*);
	len = ft_int_length(output, 0);
	flags[1] > len ? (width = flags[1]) : (width = len);
	ft_allign_uint(output, flags[0], width, len);
	return (0);
}