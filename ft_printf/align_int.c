#include "printf.h"

static void    ft_print_flag(long long output, const int flags[5])
{
    if (output < 0)
        ft_putchar('-');
    else if ((flags[0] & F_P) == F_P)
        ft_putchar('+');
    else if ((flags[0] & F_S) == F_S)
        ft_putchar(' ');
}

void    ft_align_int_left(long long output, const int *flags, int width, int len)
{
    int len2;

    len2 = ft_int_perc_len(output, flags);
    len > len2 ? width -= len : (width -= len2);

    ft_print_flag(output, flags);
    ft_putnbr_sign(output, len, len2);
    while (width > 0)
    {
        ft_putchar(' ');
        width--;
    }
}

void    ft_align_int_right(long long output, const int *flags, int width, int len)
{
    int len2;

    len2 = ft_int_perc_len(output, flags);
    len > len2 ? width -= len : (width -= len2);
    if ((flags[0] & F_Z) == F_Z)
        ft_print_flag(output, flags);
    while (width > 0) {
        if (flags[2] > -2)
            ft_putchar(' ');
        else if ((flags[0] & F_Z) == F_Z)
            ft_putchar('0');
        else
            ft_putchar(' ');
        width--;
    }
    if ((flags[0] & F_Z) != F_Z)
        ft_print_flag(output, flags);
    ft_putnbr_sign(output, len, len2);
}

void 	ft_align_int(long long output, const int *flags, int width, int len)
{
    if ((flags[2] == -1 || flags[2] == 0) && output == 0)
    {
        if (width == 1)
            width = 0;
        while (width--)
            ft_putchar(' ');
    }
    else if ((flags[0] & F_M) == F_M)
        ft_align_int_left(output, flags, width, len);
    else
        ft_align_int_right(output, flags, width, len);
}