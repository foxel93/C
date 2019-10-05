#include "printf.h"

int    spec_char(va_list *args, const int flags[5])
{
    char output;

    output = (char)va_arg(*args, int);
    ft_putchar(output);
    return (1);
}

int    spec_string(va_list *args, const int flags[5])
{
    char *output;
    int  len;

    len = 6;
    output = va_arg(*args, char*);
    if (output != NULL)
        len = ft_strlen(output);
    else
        output = "(null)";


    ft_putstr(output);
    return (1);
}

void	ft_putadr(unsigned long n, int *p)
{
    if (n > 15)
    {
        ft_putadr((n / 16), p);
        ft_putadr((n % 16), p);
    }
    else if (n < 10)
    {
        (*p)++;
        ft_putchar((char)(n + '0'));
    }
    else
    {
        (*p)++;
        n == 10 ? ft_putchar('a') : 0;
        n == 11 ? ft_putchar('b') : 0;
        n == 12 ? ft_putchar('c') : 0;
        n == 13 ? ft_putchar('d') : 0;
        n == 14 ? ft_putchar('e') : 0;
        n == 15 ? ft_putchar('f') : 0;
    }
}

int    spec_pointer(va_list *args, const int flags[5])
{
    void			*output;
    unsigned long	address;
    int             len;

    len = 0;
    output = va_arg(*args, void*);
    address = (unsigned long)(output);
    ft_putstr("0x");
    ft_putadr(address, &len);
    return (1);
}

int spec_per(va_list *args, const int flags[5])
{
    ft_putchar('%');
    return (1);
}
