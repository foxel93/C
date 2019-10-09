#include "../includes/printf.h"

static void ft_align(int *flags, int len, size_t *p)
{
	while (len-- > 0)
	{
		ft_putchar_index(' ', p, flags[9]);
	}
}

int ft_isnan(long double num, int *flags, size_t *p)
{
	int width;

	if (num != num)
	{
		width = flags[1] - 4;
		if ((flags[0] & F_M) == F_M)
			ft_align(flags, width, p);
		if (flags[4] == 'f')
			ft_putstr_index("-nan", p, flags[9]);
		else if (flags[4] == 'F')
			ft_putstr_index("-NAN", p, flags[9]);
		if ((flags[0] & F_M) != F_M)
			ft_align(flags, width, p);
		return (0);
	}
	return (1);
}

int ft_isplus_inf(long double num, int *flags, size_t *p)
{
	int width;

	if (num == 1.0 / 0.0)
	{
		width = flags[1] - 3;
		if ((flags[0] & F_M) == F_M)
			ft_align(flags, width, p);
		if (flags[4] == 'f')
			ft_putstr_index("inf", p, flags[9]);
		else if (flags[4] == 'F')
			ft_putstr_index("INF", p, flags[9]);
		if ((flags[0] & F_M) != F_M)
			ft_align(flags, width, p);
		return (0);
	}
	return (1);
}

int ft_isminus_inf(long double num, int *flags, size_t *p)
{
	int width;

	if (num == -1.0 / 0.0)
	{
		width = flags[1] - 4;
		if ((flags[0] & F_M) == F_M)
			ft_align(flags, width, p);
		if (flags[4] == 'f')
			ft_putstr_index("-inf", p, flags[9]);
		else if (flags[4] == 'F')
			ft_putstr_index("-INF", p, flags[9]);
		if ((flags[0] & F_M) != F_M)
			ft_align(flags, width, p);
		return (0);
	}
	return (1);
}