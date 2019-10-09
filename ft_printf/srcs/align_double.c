#include "../includes/printf.h"

static void ft_print_flag(long double output, const int *flags, size_t *p)
{
	if ((output * ft_pow(10, flags[2])) < 0 || output == -0.0)
		ft_putchar_index('-', p, flags[9]);
	else if ((flags[0] & F_P) == F_P)
		ft_putchar_index('+', p, flags[9]);
	else if ((flags[0] & F_S) == F_S)
		ft_putchar_index(' ', p, flags[9]);
}

static void ft_align_double_left(long double output, const int *flags, char *str, size_t *p)
{
	int part;

	part = flags[5];
	ft_print_flag(output, flags, p);
	ft_putstr_index(str, p, flags[9]);
	free(str);
	while (part > 0)
	{
		ft_putchar_index(' ', p, flags[9]);
		part--;
	}
}

static void ft_align_double_right(long double output, const int *flags, char *str, size_t *p)
{
	int part;

	part = flags[5];
	if ((flags[0] & F_Z) == F_Z)
		ft_print_flag(output, flags, p);
	while (part > 0)
	{
		if ((flags[0] & F_Z) == F_Z)
			ft_putchar_index('0', p, flags[9]);
		else
			ft_putchar_index(' ', p, flags[9]);
		part--;
	}
	if ((flags[0] & F_Z) != F_Z)
		ft_print_flag(output, flags, p);
	ft_putstr_index(str, p, flags[9]);
	free(str);
}

void ft_align_double(long double output, int *flags, char *str, size_t *p)
{
	if ((int) (output) == 0)
		flags[5]--;
	if ((flags[0] & F_M) == F_M)
		ft_align_double_left(output, flags, str, p);
	else
		ft_align_double_right(output, flags, str, p);
}

