#include "printf.h"

static  void ft_align(int len)
{
    while (len-- > 0)
    {
        ft_putchar(' ');
    }
}

int ft_isnan(long double num, const int flags[5])
{
    int width;

    if (num != num)
    {
        width = flags[1] - 4;
        if ((flags[0] & F_M) == F_M)
            ft_align(width);
        if (flags[4] == 'f')
           ft_putstr("-nan");
        else if (flags[4] == 'F')
           ft_putstr("-NAN");
        if ((flags[0] & F_M) != F_M)
            ft_align(width);
        return (0);
    }
     return (1);
}

int ft_isplus_inf(long double num, const int flags[5])
{
    int width;

    if (num == 1.0/0.0)
    {
        width = flags[1] - 3;
        if ((flags[0] & F_M) == F_M)
            ft_align(width);
        if (flags[4] == 'f')
            ft_putstr("inf");
        else if (flags[4] == 'F')
            ft_putstr("INF");
        if ((flags[0] & F_M) != F_M)
            ft_align(width);
        return (0);
    }
    return (1);
}

int ft_isminus_inf(long double num, const int flags[5])
{
    int width;

    if (num == -1.0/0.0)
    {
        width = flags[1] - 4;
        if ((flags[0] & F_M) == F_M)
            ft_align(width);
        if (flags[4] == 'f')
            ft_putstr("-inf");
        else if (flags[4] == 'F')
            ft_putstr("-INF");
        if ((flags[0] & F_M) != F_M)
            ft_align(width);
        return (0);
    }
    return (1);
}