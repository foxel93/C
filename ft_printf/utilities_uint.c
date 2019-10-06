#include "printf.h"

static void    ft_print_hex(int a, int n)
{
    if (a == 1)
    {
        n == 10 ?  ft_putchar('a') : 0;
        n == 11 ?  ft_putchar('b') : 0;
        n == 12 ?  ft_putchar('c') : 0;
        n == 13 ?  ft_putchar('d') : 0;
        n == 14 ?  ft_putchar('e') : 0;
        n == 15 ?  ft_putchar('f') : 0;
    }
    if (a == 2)
    {
        n == 10 ?  ft_putchar('A') : 0;
        n == 11 ?  ft_putchar('B') : 0;
        n == 12 ?  ft_putchar('C') : 0;
        n == 13 ?  ft_putchar('D') : 0;
        n == 14 ?  ft_putchar('E') : 0;
        n == 15 ?  ft_putchar('F') : 0;
    }
}

void	ft_putnbr_unsign(unsigned long long n, int len, int len2, int base)
{
    int a;

    base == 32 && (base = 16) ? a = 2 : (a = 1);
    if (len2 > -1)
    {
        base == 8 ? len2-- : 0;
        base == 16 ? len2 -= 2 : 0;
        while (len++ < len2)
            ft_putchar('0');
    }
    if (n >= base)
    {
        ft_putnbr_unsign((n / base), 0, 0, base * a);
        ft_putnbr_unsign((n % base), 0, 0, base * a);
    }
    else
    {
        ft_isdigit((int)n + '0') ? ft_putchar((char) ((int)n + '0')) : 0;
        base == 16 ? ft_print_hex(a, (int)n) : 0;
    }
}
