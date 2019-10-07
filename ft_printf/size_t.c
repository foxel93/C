#include "printf.h"

int print_z(va_list *args, const int flags[5])
{
    int len;
    size_t output;
    int width;

    output = (size_t)va_arg(*args, void*);
    len = ft_int_length(output, flags);
    flags[1] > len ? (width = flags[1]) : (width = len);
    flags[2] > width ? (width = flags[2]) : 0;
    ft_align_int(output, flags, width, len);
    return (1);
}

int print_zu(va_list *args, const int flags[5])
{
    int len;
    ssize_t output;
    int width;
    int base;

    base = 10;
    flags[4] == 'o' ? base = 8 : 0;
    flags[4] == 'x' ? base = 16 : 0;
    flags[4] == 'X' ? base = 32 : 0;
    output = (ssize_t)va_arg(*args, void*);
    len = ft_uint_length(output, flags, base);
    flags[1] > len ? (width = flags[1]) : (width = len);
    flags[2] > width ? (width = flags[2]) : 0;
    ft_align_uint(output, flags, width, len);
    return (1);
}