#include "printf.h"

static int    ft_print_flag(const int flags[5])
{
    int a;

    a = 0;
    if ((flags[0] & F_H) == F_H)
    {
        flags[4] == 'o' ?  ft_putchar('0'), a = 1 : 0;
        flags[4] == 'x' ?  ft_putstr("0x"), a = 2 : 0;
        flags[4] == 'X' ?  ft_putstr("0X"), a = 2 : 0;
    }
    return (a);
}

void    ft_align_uint_left(unsigned long long output, const int *flags, int width, int len)
{
    int len2;
    int base;

    base = 10;
    flags[4] == 'o' ? base = 8 : 0;
    flags[4] == 'x' ? base = 16 : 0;
    flags[4] == 'X' ? base = 32 : 0;
    len2 = ft_uint_perc_len(output, flags, base);
    len > len2 ? width -= len : (width -= len2);
    ft_print_flag(flags);
    ft_putnbr_unsign(output, len, len2, base);
    while (width > 0)
    {
        ft_putchar(' ');
        width--;
    }
}

void    ft_align_uint_right(unsigned long long output, const int *flags, int width, int len)
{
    int len2;
    int base;

    base = 10;
    flags[4] == 'o' ? base = 8 : 0;
    flags[4] == 'x' ? base = 16 : 0;
    flags[4] == 'X' ? base = 32 : 0;
    len2 = ft_uint_perc_len(output, flags, base);
    len > len2 ? width -= len : (width -= len2);

    if (((flags[0] & F_Z) == F_Z && flags[2] < -1))
        ft_print_flag(flags);
    while (width > 0) {
        if (flags[2] > -2)
            ft_putchar(' ');
        else if ((flags[0] & F_Z) == F_Z)
            ft_putchar('0');
        else
            ft_putchar(' ');
        width--;
    }
    if (((flags[0] & F_Z) == F_Z && flags[2] >= -1) || (flags[0] & F_Z) != F_Z)
        ft_print_flag(flags);
    ft_putnbr_unsign(output, len, len2, base);
}

void 	ft_align_uint(unsigned long long output, const int *flags, int width, int len)
{
    if ((flags[2] == -1 || flags[2] == 0) && output == 0)
    {
        if  (width == 1)
            width = 0;
        while (width--)
            ft_putchar(' ');
    }
    else if ((flags[0] & F_M) == F_M)
        ft_align_uint_left(output, flags, width, len);
    else
        ft_align_uint_right(output, flags, width, len);
}

