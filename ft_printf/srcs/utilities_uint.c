#include "../includes/printf.h"

static void ft_print_hex(int a, int n, int *flags, size_t *p)
{
	n < 0 ? n = -n : 0;
	if (a == 1)
		ft_putchar_index(n - 10 + 'a', p, flags[9]);
	if (a == 2)
		ft_putchar_index(n - 10 + 'A', p, flags[9]);
}

void ft_putnbr_unsign(unsigned long long n, int *flags, int base, size_t *p)
{
	int a;

	base == 32 && (base = 16) ? a = 2 : (a = 1);
	if (flags[7] > -1)
	{
		base == 8 ? flags[7]-- : 0;
		base == 16 ? flags[7] -= 2 : 0;
		while (flags[6]++ < flags[7])
			ft_putchar_index('0', p, flags[9]);
		flags[7] = -1;
	}
	if (n >= (unsigned long long)base)
	{
		ft_putnbr_unsign((n / base), flags, base * a, p);
		ft_putnbr_unsign((n % base), flags, base * a, p);
	}
	else
	{
		if (ft_isdigit((int) n + '0'))
			ft_putchar_index(n + '0', p, flags[9]);
		else if (base == 16)
			ft_print_hex(a, (int) n, flags, p);
	}
}
