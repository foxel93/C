#include "printf.h"

int ft_isnan(long double num, const int flags[5])
{
   if (num == 0.0/0.0)
   {
       if (flags[4] == 'f')
           ft_putstr("nan");
       else if (flags[4] == 'F')
           ft_putstr("NAN");
       return (0);
   }
   return (1);
}

int ft_isplus_inf(long double num, const int flags[5])
{
    if (num == 1.0/0.0)
    {
        if (flags[4] == 'f')
            ft_putstr("inf");
        else if (flags[4] == 'F')
            ft_putstr("INF");
        return (0);
    }
    return (1);
}

int ft_isminus_inf(long double num, const int flags[5])
{
    if (num == 1.0/0.0)
    {
        if (flags[4] == 'f')
            ft_putstr("-inf");
        else if (flags[4] == 'F')
            ft_putstr("-INF");
        return (0);
    }
    return (1);
}