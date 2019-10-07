#include "printf.h"

static void    ft_print_flag(double output, const int flags[5])
{
    if ((output * ft_pow(10, flags[2])) < 0 || output == -0.0)
        ft_putchar('-');
    else if ((flags[0] & F_P) == F_P)
        ft_putchar('+');
    else if ((flags[0] & F_S) == F_S)
        ft_putchar(' ');
}

void    ft_align_double_left(double output, const int *flags, int part, char *str)
{
    ft_print_flag(output, flags);
    ft_putstr(str);
    free(str);
    while (part > 0)
    {
        ft_putchar(' ');
        part--;
    }
}

void    ft_align_double_right(double output, const int *flags, int part, char *str)
{
    if ((flags[0] & F_Z) == F_Z)
        ft_print_flag(output, flags);
    while (part > 0) {
        if ((flags[0] & F_Z) == F_Z)
            ft_putchar('0');
        else
            ft_putchar(' ');
        part--;
    }
    if ((flags[0] & F_Z) != F_Z)
        ft_print_flag(output, flags);
    ft_putstr(str);
    free(str);
}

void 	ft_align_double(double output, const int *flags, int part, char *str)
{
    if ((int)(output) == 0)
        part--;
    if ((flags[0] & F_M) == F_M)
        ft_align_double_left(output, flags, part, str);
    else
        ft_align_double_right(output, flags, part, str);
}

