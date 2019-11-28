/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialleen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 10:56:57 by ialleen           #+#    #+#             */
/*   Updated: 2019/10/11 16:33:01 by ialleen          ###   ########.fr       */
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
# include "libft.h"

# define F_H		0x20
# define F_Z		0x10
# define F_M		0x08
# define F_S		0x04
# define F_P		0x02

int		parse_width(const char **str, va_list *arg, int *flags);
int		parse_precision(const char **str, va_list *arg);
int		parse_modificators(const char **str);
int		parse_flags(const char **str);
int		parse_specificators(const char **str);

int		spec_char(va_list *args, int *flags, size_t *p);
int		spec_string(va_list *args, int *flags, size_t *p);
int		spec_pointer(va_list *args, int *flags, size_t *p);
int		spec_per(int *flags, size_t *p);

int		ft_printf(const char *format, ...);
int		ft_vfprintf(int fd, const char **format, va_list *args);
int		parse_string(const char **str, va_list *args, size_t *p, int fd);

int		spec_signed(va_list *args, int *flags, size_t *p);
int		spec_unsigned(va_list *args, int *flags, size_t *p);
int		spec_double(va_list *args, int *flags, size_t *p);

int		ft_int_length(ssize_t num, int *flags);
int		ft_int_perc_len(ssize_t num, int *flags);
int		ft_uint_length(size_t num, int *flags, int base);
int		ft_uint_perc_len(size_t num, int *flags, int base);

int		ft_print_bin(size_t const size, void const *const ptr,
		int *flags, size_t *p);

int		print_ldouble(va_list *args, int *flags, size_t *p);
int		print_double(va_list *args, int *flags, size_t *p);

void	ft_align_double(long long left, long long right, int *flags, size_t *p);

int		ft_isnan(long double num, int *flags, size_t *p);
int		ft_isplus_inf(long double num, int *flags, size_t *p);
int		ft_isminus_inf(long double num, int *flags, size_t *p);

int		print_zu(va_list *args, int *flags, size_t *p);
int		print_z(va_list *args, int *flags, size_t *p);

int		print_hhd(va_list *args, int *flags, size_t *p);
int		print_hd(va_list *args, int *flags, size_t *p);
int		print_ld(va_list *args, int *flags, size_t *p);
int		print_lld(va_list *args, int *flags, size_t *p);
int		print_d(va_list *args, int *flags, size_t *p);

int		print_hhu(va_list *args, int *flags, size_t *p);
int		print_hu(va_list *args, int *flags, size_t *p);
int		print_lu(va_list *args, int *flags, size_t *p);
int		print_llu(va_list *args, int *flags, size_t *p);
int		print_u(va_list *args, int *flags, size_t *p);

void	ft_putnbr_unsign(unsigned long long n, int *flags, int base, size_t *p);
void	ft_align_uint(unsigned long long o, int *flags, int len, size_t *p);

void	ft_putnbr_sign(long long n, int *flags, size_t *p);
void	ft_align_int(long long output, int *flags, int len, size_t *p);

int		ft_putchar_index(char c, size_t *p, int fd);
int		ft_putstr_index(char *str, size_t *p, int fd);

void	ft_print_hex(int a, int n, int *flags, size_t *p);
void	ft_putnbr_double(long long n, int *flags, size_t *p);
#endif
