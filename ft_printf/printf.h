/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialleen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 10:56:57 by ialleen           #+#    #+#             */
/*   Updated: 2019/10/06 14:54:47 by ialleen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <string.h>
# include <ctype.h>
# include <limits.h>
# include <stdlib.h>
# include "libft/libft.h"

# define F_H		0x20
# define F_Z		0x10
# define F_M		0x08
# define F_S		0x04
# define F_P		0x02

int		parse_width(const char **str, va_list *arg);
int		parse_precision(const char **str, va_list *arg);
int		parse_modificators(const char **str);
int		parse_flags(const char **str);
int		parse_specificators(const char **str);

int		spec_char(va_list *args, const int flags[5]);
int		spec_string(va_list *args, const int flags[5]);
int		spec_pointer(va_list *args, const int flags[5]);
int		spec_per(void);

int		ft_printf(const char *format, ...);

int		parse_string(const char **str, va_list *args);

int		spec_signed(va_list *args, const int flags[5]);
int		spec_unsigned(va_list *args, const int flags[5]);
int		spec_float(va_list *args, const int flags[5]);

size_t 	ft_int_length(ssize_t num, int flag);
void	ft_putadr(unsigned long n, int *p);
void	print_flags(const int flags[5]);


int 	print_hhd(va_list *args, const int flags[5]);
int 	print_hd(va_list *args, const int flags[5]);
int 	print_ld(va_list *args, const int flags[5]);
int 	print_lld(va_list *args, const int flags[5]);
int 	print_d(va_list *args, const int flags[5]);

int 	print_hhu(va_list *args, const int flags[5]);
int 	print_hu(va_list *args, const int flags[5]);
int 	print_lu(va_list *args, const int flags[5]);
int 	print_llu(va_list *args, const int flags[5]);
int 	print_u(va_list *args, const int flags[5]);

void	ft_putnbr_unsign(long long n, int flag);
void 	ft_allign_uint(long long output, int flags, int width, int len);

void	ft_putnbr_sign(long long n, int flag);
void 	ft_allign_int(long long output, int flags, int width, int len);

#endif
