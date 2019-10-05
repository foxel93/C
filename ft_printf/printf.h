#ifndef FT_PRINTF_PRINTF_H
#define FT_PRINTF_PRINTF_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <stdlib.h>
#include "libft/libft.h"

//FLAG
#define F_HASH  0x20
#define F_ZERO  0x10
#define F_MINUS 0x08
#define F_SPACE 0x04
#define F_PLUS  0x02

int     parse_width(const char **str, va_list *arg);
int     parse_precision(const char **str, va_list *arg);
int     parse_modificators(const char **str);
int     parse_flags(const char **str);
int     parse_specificators(const char **str);

int     spec_char(va_list *args, const int flags[5]);
int     spec_string(va_list *args, const int flags[5]);
void	ft_putadr(unsigned long n, int *p);
int     spec_pointer(va_list *args, const int flags[5]);
int     spec_per(va_list *args, const int flags[5]);

int     ft_printf(const char *format, ...);

int     parse_string(const char **str, va_list *args);

int    spec_signed(va_list *args, const int flags[5]);
int    spec_unsigned(va_list *args, const int flags[5]);
int    spec_float(va_list *args, const int flags[5]);

#endif FT_PRINTF_PRINTF_H
